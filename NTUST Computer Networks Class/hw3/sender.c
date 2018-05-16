#define SRV_IP "127.0.0.1"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFLEN 512
#define NPACK 50
#define PORT 9930
#define BUF_SIZE 1000

#define SLOW_START 1
#define C_AVOID 2
#define FAST_RECOVERY 3

/* diep(), #includes and #defines like in the server */

struct sockaddr_in initial() {
    struct sockaddr_in si_other;

    memset((char *)&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
    if (inet_aton(SRV_IP, &si_other.sin_addr) == 0) {
        fprintf(stderr, "inet_aton() failed\n");
        return si_other;
    }

    return si_other;
}

int connect_socket(void) {
    int s;

    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
        perror("socket");

    return s;
}

void close_socket(int s) {
    close(s);
}

void print_cwnd(int cwnd) {
    printf("CWND = %d\n", cwnd);
}

void print_duplicate() {
    printf("3 duplicate ack\n");
}

void print_timeout() {
    printf("Time out\n");
}

int main(void) {
    struct sockaddr_in si_other, recv_ip;
    int s, i, slen = sizeof(si_other), rlen = sizeof(recv_ip);
    char buf[BUFLEN];

    struct timeval tv;
    fd_set readfds;

    si_other = initial();
    s = connect_socket();

    int send_buffer[NPACK + 1];
    int cwnd = 1;
    double cwnd_double = 1.0;
    int lastByteSent = 0;
    int lastByteAcked = 0;
    int ssthresh = 10;

    int pre_acked;
    int acked = 0;
    int duplicate_ack = 0;

    int state = SLOW_START;

    for (i = 0; i < NPACK + 1; i++) {
        send_buffer[i] = i;
    }

    /* Insert your codes below */
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    pre_acked = lastByteAcked = 0;
    int rv;
    int C_AVOID_count = 0; /* count the amount of acks in C_AVOID state  */
    int last_duplicate_count = 0;
    int changeFromFastRecovery = 0;
    /* last new ack make state change form FastRecovery to C_AVOID */
    while (lastByteAcked <= NPACK) {
        /* send the packet if there is any data which can be sent in cwnd */
        while (lastByteSent == 0 ||
               (lastByteSent < lastByteAcked + cwnd - 1 && lastByteSent < NPACK)) {
            memset(buf, 0, BUFLEN);
            sprintf(buf, "%d", send_buffer[++lastByteSent]);
            sendto(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, (socklen_t)slen);
        }
        /* listen to the socket and check the ack  */
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        FD_ZERO(&readfds);
        FD_SET(s, &readfds);
        select(s + 1, &readfds, NULL, NULL, &tv);
        if (!FD_ISSET(s, &readfds)) {
            /* timeout */
            /* modify the value */
            ssthresh = (cwnd >> 1);
            cwnd = 1;
            duplicate_ack = 0;
            state = SLOW_START;
            printf("%d:", lastByteAcked);
            print_timeout();
            /* resend  data */
            lastByteSent = lastByteAcked - 1;
            continue;
        } else {
            /* receive the ack */
            recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&recv_ip, (socklen_t *)&rlen);
            acked = atoi(buf);
            if (lastByteAcked == acked) {
                /* ack is as same as lastByteAck */
                if (last_duplicate_count > 0 && state == C_AVOID) {
                    /* The data which resent when 3-duplicate happened but some of the data had been
                     * received before resending. In this condition, after resending the data, it
                     * would occur 3-duplicate. To avoid this condition, use an tolerate value to
                     * consume these duplicateAcks after the state change from FAST_RECOVERY to
                     * C_AVOID */
                    last_duplicate_count--;
                    continue;
                }
                duplicate_ack++;
                if (state == FAST_RECOVERY) {
                    cwnd++;
                } else {
                    if (duplicate_ack > 2) {
                        /* if duplicateAcks accumulate over than, change the state to FAST_RECOVERY
                         */
                        print_duplicate();
                        ssthresh = cwnd / 2;
                        last_duplicate_count = cwnd = ssthresh + 3;
                        state = FAST_RECOVERY;
                        lastByteSent = lastByteAcked - 1;
                        C_AVOID_count = 0;
                    }
                }
            } else if (lastByteAcked < acked) {
                /* receive new ack */
                lastByteAcked = acked;
                if (lastByteSent < lastByteAcked - 1)
                    lastByteSent = lastByteAcked - 1;
                if (state == SLOW_START) {
                    cwnd++;
                    if (cwnd >= ssthresh) {
                        state = C_AVOID;
                        C_AVOID_count = 0;
                    }
                } else if (state == FAST_RECOVERY) {
                    changeFromFastRecovery = 1;
                    if (last_duplicate_count > duplicate_ack)
                        last_duplicate_count = duplicate_ack;
                    cwnd = ssthresh;
                    C_AVOID_count = 0;
                    state = C_AVOID;
                } else {
                    if (changeFromFastRecovery)
                        last_duplicate_count = changeFromFastRecovery = 0;
                    C_AVOID_count++;
                    if (C_AVOID_count == cwnd) {
                        cwnd++;
                        C_AVOID_count = 0;
                    }
                }
                duplicate_ack = 0;
            }
        }
        print_cwnd(cwnd);
    }
    /* Insert your codes above */
    close_socket(s);
    return 0;
}
