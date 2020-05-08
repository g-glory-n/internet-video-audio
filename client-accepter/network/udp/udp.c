#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int connect_sockfd;
	struct sockaddr_in server_addr;
	char client_buffer[20] = "I am g-glory-n";

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1024);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect_sockfd = (int)socket((int)AF_INET, (int)SOCK_DGRAM, (int)0);

	while(1)
	{
		sleep(1);
		sendto((int)connect_sockfd, (const void *)client_buffer, (size_t)20, (int)0, (struct sockaddr *)&server_addr, (socklen_t)sizeof(server_addr));
	}
	return 0;
}
