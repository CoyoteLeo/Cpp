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
struct sockaddr_in si_other, recv_ip;
int s, i, slen = sizeof(si_other), rlen = sizeof(recv_ip);
char buf[BUFLEN];

struct timeval tv;
fd_set readfds;

int send_buffer[NPACK + 1];
int cwnd = 1;
int cwnd_temp = 1;  //
double cwnd_double = 1.0;
int lastByteSent = 0;
int lastByteAcked = 0;
int ssthresh = 10;

int pre_acked;
int acked = 0;
int duplicate_ack = 0;

int state = SLOW_START;

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

void print_ssthresh() {
    printf("ssthresh = %d\n", ssthresh);
}

void sendnext() {
    if (lastByteSent < NPACK) {
        int i = lastByteSent + 1;
        for (i; i <= (lastByteAcked + cwnd - 1); i++) {
            memset(buf, 0, BUFLEN);
            sprintf(buf, "%d", send_buffer[i]);
            lastByteSent++;
            sendto(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, (socklen_t)slen);
            print_cwnd(cwnd);
        }
    }
}
void sendagain() {
    if (lastByteSent < NPACK) {
        int i = lastByteAcked;
        for (i; i <= (lastByteAcked + cwnd - 1); i++) {
            memset(buf, 0, BUFLEN);
            sprintf(buf, "%d", send_buffer[i]);
            sendto(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, (socklen_t)slen);
            print_cwnd(cwnd);
        }
    }
}

int main(void) {
    si_other = initial();
    s = connect_socket();

    for (i = 0; i < NPACK + 1; i++) {
        send_buffer[i] = i;
    }

    /* Insert your codes below */

    memset(buf, 0, BUFLEN);
    sprintf(buf, "%d", send_buffer[lastByteSent]);

    sendto(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, (socklen_t)slen);  //�e�ʥ]

    // print_ssthresh();
    print_cwnd(cwnd);

    while (lastByteSent < NPACK) {
        //�P�_TIMEOUT
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        FD_ZERO(&readfds);
        FD_SET(s, &readfds);
        select(s + 1, &readfds, NULL, NULL, &tv);

        if (!FD_ISSET(s, &readfds)) {
            ssthresh = cwnd / 2;
            cwnd = 1;
            duplicate_ack = 0;
            state = SLOW_START;
            //
            print_timeout();
            print_cwnd(cwnd);
            sendagain();
        } else  ////�S��TIMEOUT�N
        {
            recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&recv_ip, (socklen_t *)&rlen);
            acked = atoi(buf);
            printf("Received acked from %s:%d\nSeq: %d\n", inet_ntoa(si_other.sin_addr),
                   ntohs(si_other.sin_port), acked);

            switch (state) {
                case SLOW_START:
                    if (lastByteAcked == acked)  //�p�G�O���ƪ��ȶ�????
                    {
                        duplicate_ack++;
                        if (duplicate_ack == 3) {
                            ssthresh = cwnd / 2;
                            cwnd = ssthresh + 3;
                            state = FAST_RECOVERY;
                            print_cwnd(cwnd);
                            sendnext();
                        } else {
                            print_cwnd(cwnd);
                            // continue;
                        }
                    } else {
                        lastByteAcked = acked;
                        cwnd++;
                        duplicate_ack = 0;
                        if (cwnd >= ssthresh) {
                            state = C_AVOID;
                            cwnd_temp = cwnd;
                            cwnd_double = (double)cwnd_temp;
                            print_cwnd(cwnd);
                        }
                        sendnext();
                    }
                    break;
                case C_AVOID:
                    if (lastByteAcked == acked) {
                        duplicate_ack++;
                        if (duplicate_ack == 3) {
                            ssthresh = cwnd / 2;
                            cwnd = ssthresh + 3;
                            state = FAST_RECOVERY;
                            print_cwnd(cwnd);
                            sendagain();
                        } else {
                            print_cwnd(cwnd);
                            // continue;

                            sendnext();  //���ӨS��
                        }
                    } else {
                        cwnd_double += 1 / cwnd_temp;  //���O�����o��
                        cwnd = (int)cwnd_double;
                        duplicate_ack = 0;
                        print_cwnd(cwnd);
                        sendnext();
                    }
                    break;
                case FAST_RECOVERY:
                    if (lastByteAcked == acked) {
                        cwnd++;
                        print_cwnd(cwnd);
                        sendnext();
                    } else {
                        cwnd = ssthresh;  //�b FAST_RECOVERY??
                        duplicate_ack = 0;
                        state = C_AVOID;
                        cwnd_temp = cwnd;                 //�o�Ӥ]���O����
                        cwnd_double = (double)cwnd_temp;  //
                        print_cwnd(cwnd);
                        sendnext();
                    }
                    break;
            }
        }
    }

    /* Insert your codes above */

    close_socket(s);
    return 0;
}
