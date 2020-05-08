#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define buffer_size 100

int main(void)
{
	int length;
	char client_buffer[buffer_size + 1];
	int server_sockfd, client_sockfd;
	struct sockaddr_in server_addr, client_addr;

//	memset(&server_addr, 0, sizeof(server_addr));
	memset(&client_addr, 0, sizeof(client_addr)); //initailization

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("192.168.0.109");
	server_addr.sin_port = htons(8000);
	if((client_sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket failed");
		return -1;
	}

	if(connect(client_sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("connect failed");
		return -1;
	}

//	printf("client ip is : %s\n"/*, inet_ntoa(client_addr.sin_addr)*/, inet_ntoa(server_addr.sin_addr));
	printf("server ip is %s\n", inet_ntoa(server_addr.sin_addr));
	length = recv((int)client_sockfd, (void *)client_buffer, (size_t)buffer_size, (int)0);
	length = send((int)client_sockfd, (void *)"welcome !", (size_t)buffer_size, (int)0);
	
	printf("%s\n", client_buffer);

	while(1)
	{
		printf("enter string to send :\n");

 		scanf("%[^\n]", client_buffer);
		getchar();

//		gets(client_buffer);
//		fscanf(stdin, "%s", client_buffer);
		length = send((int)client_sockfd, (void *)client_buffer, (size_t)buffer_size, (int)0);
		if(!strcmp(client_buffer, "quit"))
			break;
	}

	close(client_sockfd);
	return 0;
}
