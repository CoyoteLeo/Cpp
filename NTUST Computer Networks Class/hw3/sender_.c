#define SRV_IP "127.0.0.1"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
     
#define BUFLEN 512
#define NPACK 50
#define PORT 9930
#define BUF_SIZE 1000

#define SLOW_START 1
#define C_AVOID 2
#define FAST_RECOVERY 3

#define NORMAL 1
#define RE_TRANSMIT 2

 /* diep(), #includes and #defines like in the server */

struct sockaddr_in initial(){
	struct sockaddr_in si_other;

	memset((char *) &si_other, 0, sizeof(si_other));
    	si_other.sin_family = AF_INET;
    	si_other.sin_port = htons(PORT);
    	if (inet_aton(SRV_IP, &si_other.sin_addr)==0){
    		fprintf(stderr, "inet_aton() failed\n");
    		return si_other;
    	}

	return si_other;
}

int send_buffer[NPACK + 1];
int cwnd = 1;
int cwnd_temp = 1;
double cwnd_double = 1.0;
int lastByteSent = 1;
int lastByteAcked = 0;
int ssthresh = 10;

int pre_acked;
int acked = 0;
int duplicate_ack = 0;

int trans_state = NORMAL;

int state = SLOW_START;
 
int connect_socket(void){
     	int s;
     
    	if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    		perror("socket");
	
    	return s;
}

void close_socket(int s){
	close(s);
}

void print_cwnd(int cwnd){
	printf("CWND = %d\n\n", cwnd);
}

void print_duplicate(){
	printf("3 DUPLICATE ACK\n");
}

void print_timeout(){
	printf("TIME OUT\n");
}

void print_ssthresh(){
	printf("ssthresh = %d\n", ssthresh);
}

int main(void){
	struct sockaddr_in si_other, recv_ip;
	int s, i, slen=sizeof(si_other), rlen = sizeof(recv_ip);
     	char buf[BUFLEN];

	struct timeval tv;
  	fd_set readfds;

	si_other = initial();
	s = connect_socket();

	for(i = 0; i < NPACK + 1; i++){
		send_buffer[i] = i;
	}

/* Insert your codes below */

	memset(buf, 0, BUFLEN);
	sprintf(buf, "%d", send_buffer[lastByteSent]);

	sendto(s, buf, BUFLEN, 0, (struct sockaddr*) &si_other, (socklen_t) slen);

	printf("Sending packet to %s:%d\nSeq: %d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), send_buffer[lastByteSent]);
	print_ssthresh();
	print_cwnd(cwnd);

	while (lastByteAcked < NPACK+1)
	{	
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		FD_ZERO(&readfds);
		FD_SET(s, &readfds);
		select(s+1, &readfds, NULL, NULL, &tv);

		if (!FD_ISSET(s, &readfds))
		{
			ssthresh = cwnd / 2;
			cwnd = 1;
			duplicate_ack = 0;
			state = SLOW_START;
			trans_state = RE_TRANSMIT;
			print_timeout();
			print_ssthresh();
			print_cwnd(cwnd);
		}
		else
		{
			recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*) &recv_ip, (socklen_t*) &rlen);
			acked = atoi(buf);
			if (lastByteAcked == acked)
			{	
				if (state == FAST_RECOVERY)
				{
					cwnd++;
					trans_state = NORMAL;
					printf("Received acked from %s:%d\nSeq: %d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), acked);
					printf("State: %d\n", state);
					print_ssthresh();
					print_cwnd(cwnd); 
				}
				else 
				{
					duplicate_ack++;
					if (duplicate_ack == 3)
					{
						ssthresh = cwnd / 2;
						cwnd = ssthresh + 3;
						state = FAST_RECOVERY;
						trans_state = RE_TRANSMIT;
						print_duplicate();
						printf("State: %d\n", state);
						print_ssthresh();
						print_cwnd(cwnd); 
					}
					else
					{
						printf("Received acked from %s:%d\nSeq: %d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), acked);
						printf("State: %d\n", state);
						print_ssthresh();
						print_cwnd(cwnd); 
						continue;
					}
				}
			}
			else
			{
				lastByteAcked = acked;
				duplicate_ack = 0;
				trans_state = NORMAL;
				if (state == SLOW_START)
				{
					cwnd++;
					if (cwnd > ssthresh)
					{
						state = C_AVOID;
						cwnd_temp = cwnd;
						cwnd_double = (double) cwnd_temp;
					}
				}
				else if (state == C_AVOID)
				{
					if (cwnd-cwnd_temp >= 1)
						cwnd_temp = cwnd;
					cwnd_double += 1.0 / cwnd_temp;
					cwnd = (int) cwnd_double;
				}
				else
				{
					cwnd = ssthresh;
					state = C_AVOID;
					cwnd_temp = cwnd;
					cwnd_double = (double) cwnd_temp;
				}
				printf("Received acked from %s:%d\nSeq: %d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), acked);
				printf("State: %d\n", state);
				print_ssthresh();
				print_cwnd(cwnd); 
			}
		}

		if (lastByteSent >= NPACK)
			continue;
		else
		{
			if (trans_state == NORMAL)
			{
				//LBS stands for lastByteSent
				int tempLBS = lastByteSent;
				for (int i = tempLBS+1; i <= (lastByteAcked+cwnd-1); i++)
				{
					memset(buf, 0, BUFLEN);
					sprintf(buf, "%d", send_buffer[i]);
					lastByteSent++;
					sendto(s, buf, BUFLEN, 0, (struct sockaddr*) &si_other, (socklen_t) slen);
					printf("Sending packet to %s:%d\nSeq: %d\n\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), send_buffer[i]);
					//print_ssthresh();
					//print_cwnd(cwnd); 
				}
			}
			else
			{
				for (int i = lastByteAcked; i <= (lastByteAcked+cwnd-1); i++)
				{
					memset(buf, 0, BUFLEN);
					sprintf(buf, "%d", send_buffer[i]);
					sendto(s, buf, BUFLEN, 0, (struct sockaddr*) &si_other, (socklen_t) slen);
					printf("Sending packet to %s:%d\nSeq: %d\n\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), send_buffer[i]);
					//print_ssthresh();
					//print_cwnd(cwnd);
				}
			} 
		}
	}

/* Insert your codes above */

	close_socket(s);
	return 0;
}