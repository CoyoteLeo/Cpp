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
    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        perror("socket");
    }
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
    double cwnd_double = 0;
    int cwnd_tmp = 0;
    int lastByteSent = 0;
    int lastByteAcked = 1;
    int ssthresh = 10;
    // int ssthresh = 64;

    int pre_acked = 0;
    int acked = 0;
    int duplicate_ack = 0;

    int state = SLOW_START;

    for (i = 0; i < NPACK + 1; i++) {
        send_buffer[i] = i;
    }

    /* Insert your codes below */

    tv.tv_sec = 1;
    tv.tv_usec = 0;

    while (lastByteAcked < NPACK || lastByteSent < NPACK) {
        while (lastByteSent < lastByteAcked + cwnd - 1 && lastByteSent < NPACK) {
            printf("send %d\n", lastByteSent + 1);
            memset(buf, 0, BUFLEN);
            sprintf(buf, "%d", send_buffer[++lastByteSent]);
            sendto(s, buf, cwnd, 0, (struct sockaddr *)&si_other, (socklen_t)slen);
        }
        FD_ZERO(&readfds);
        FD_SET(s, &readfds);
        select(s + 1, &readfds, NULL, NULL, &tv);
        if (!FD_ISSET(s, &readfds)) {
            // time out!
            ssthresh = cwnd / 2;
            cwnd = 1;
            state = SLOW_START;
            duplicate_ack = 0;
            print_timeout();
            print_cwnd(cwnd);

            // resend
            // lastByteSent = lastByteAcked;
            memset(buf, 0, BUFLEN);
            sprintf(buf, "%d", send_buffer[lastByteAcked]);
            sendto(s, buf, cwnd, 0, (struct sockaddr *)&si_other, (socklen_t)slen);
            printf("resend %d\n", lastByteAcked);

        } else {
            // start to listen ack
            recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&recv_ip, (socklen_t *)&rlen);
            acked = atoi(buf);
            printf("acked: %d\n", acked);
            if (lastByteAcked < acked) {
                duplicate_ack = 0;
                lastByteAcked = acked;
                // lastByteSent = acked - 1;
                if (state == SLOW_START) {
                    cwnd++;
                    printf("SLOW START: ");
                    print_cwnd(cwnd);
                    if (cwnd >= ssthresh) {
                        state = C_AVOID;
                    }
                } else if (state == C_AVOID) {
                    cwnd_tmp++;
                    if (cwnd_tmp == cwnd) {
                        cwnd++;
                        cwnd_tmp = 0;
                        printf("C AVOID: ");
                        print_cwnd(cwnd);
                    }
                }
            } else if (lastByteAcked == acked) {
                duplicate_ack++;
                if (duplicate_ack == 3) {
                    duplicate_ack = 0;
                    print_duplicate();
                    lastByteSent = lastByteAcked - 1;
                    ssthresh = cwnd / 2;
                    cwnd = ssthresh + 3;
                    print_cwnd(cwnd);
                }
            }
        }
    }
    /* Insert your codes above */

    close_socket(s);
    return 0;
}
