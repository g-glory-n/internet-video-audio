#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define buffer_size 100

int main(void)
{
	socklen_t server_sin_size;
	int server_length;
	char server_buffer[buffer_size + 1];
	int listening_sockfd;
	int connect_sockfd;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	
	memset(&server_addr, 0, sizeof(server_addr)); //initialization struct sockaddr_in
	memset(&client_addr, 0, sizeof(client_addr));
	
	server_addr.sin_family = AF_INET; //set IP communication
//	server_addr.sin_addr.s_addr = inet_addr("192.168.0.109");
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(8000);

	if((listening_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket() failed");
		return -1;
	}

	if(bind(listening_sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("bind() failed");
		return -1;
	}

	if(listen(listening_sockfd, 5) == -1)
	{
		perror("listen() failed");
		return -1;
	}

	server_sin_size = sizeof(struct sockaddr_in);
	if((connect_sockfd = accept(listening_sockfd, (struct sockaddr *)&client_addr, &server_sin_size)) == -1)
	{
		perror("accept() failed");
		return -1;
	}

	printf("server ip is : %s\n", inet_ntoa((struct in_addr)server_addr.sin_addr));
	printf("client ip is : %s\n", inet_ntoa((struct in_addr)client_addr.sin_addr));
	server_length = send((int)connect_sockfd, (void *)"welcome !", (size_t)buffer_size, (int)0);
	server_length = recv((int)connect_sockfd, (void *)server_buffer, (size_t)buffer_size, (int)0);
	printf("%s\n", server_buffer);

	while(1)
	{
		server_length = recv(connect_sockfd, (void *)server_buffer, buffer_size, 0);
		if(server_length == -1)
		{
			printf("recv() failed !\n");
			break;
		}
		printf("server has received data that is : %s\n", server_buffer);
		if(!strcmp(server_buffer, "quit"))
			break;
	}


	close(listening_sockfd);
	close(connect_sockfd);
	return 0;
}
