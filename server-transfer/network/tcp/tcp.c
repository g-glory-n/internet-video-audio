/*
 * =================================================================================================
 * tcp.c
 * =================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "tcp.h"



signed int tcp_programmer_define_signed_int__listening_sockfd;
signed int tcp_programmer_define_signed_int__connect__sockfd;
struct sockaddr_in sockaddr_in__server_addr;
struct sockaddr_in sockaddr_in__client_addr;



unsigned char *tcp_programmer_define_unsigned_char_point__picture_buffer_in = NULL;
unsigned long tcp_programmer_define_unsigned_long__size_of_recv = 0;



unsigned char *tcp_programmer_define_unsigned_char_point__picture_buffer_out = NULL;
unsigned long tcp_programmer_define_unsigned_long__size_of_send = 0;
unsigned long tcp_programmer_define_unsigned_long__size_of_out_picture_buffer = 0;



void tcp_init(void)
{

	tcp_programmer_define_unsigned_char_point__picture_buffer_in = (unsigned char *)malloc(TCP_PICTURE_WIDTH*TCP_PICTURE_HEIGHT*TCP_PICTURE_BIT_DEPTH);
	tcp_programmer_define_unsigned_char_point__picture_buffer_out = (unsigned char *)malloc(TCP_PICTURE_WIDTH*TCP_PICTURE_HEIGHT*TCP_PICTURE_BIT_DEPTH);
	tcp_programmer_define_unsigned_long__size_of_out_picture_buffer = TCP_PICTURE_WIDTH*TCP_PICTURE_HEIGHT*TCP_PICTURE_BIT_DEPTH;



/*
 * =================================================================================================
 * set the params of socket file descreptor
 * =================================================================================================
*/
	socklen_t socklen_t__server_sin_size;
	
	memset(&sockaddr_in__server_addr, 0, sizeof(sockaddr_in__server_addr)); //initialization struct sockaddr_in
	memset(&sockaddr_in__client_addr, 0, sizeof(sockaddr_in__client_addr));
	
	sockaddr_in__server_addr.sin_family = AF_INET; //set IP communication
//	sockaddr_in__server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");
	sockaddr_in__server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	sockaddr_in__server_addr.sin_port = htons(1024);

	if((tcp_programmer_define_signed_int__listening_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket() failed");
		exit(FAILURE);
	}

	if(bind(tcp_programmer_define_signed_int__listening_sockfd, (struct sockaddr*)&sockaddr_in__server_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("bind() failed");
		exit(FAILURE);
	}

	if(listen(tcp_programmer_define_signed_int__listening_sockfd, 5) == -1)
	{
		perror("listen() failed");
		exit(FAILURE);
	}

	socklen_t__server_sin_size = sizeof(struct sockaddr_in);
	if((tcp_programmer_define_signed_int__connect__sockfd = accept(tcp_programmer_define_signed_int__listening_sockfd, (struct sockaddr *)&sockaddr_in__client_addr, &socklen_t__server_sin_size)) == -1)
	{
		perror("accept() failed");
		exit(FAILURE);
	}

	printf("server ip is : %s\n", inet_ntoa((struct in_addr)sockaddr_in__server_addr.sin_addr));
	printf("client ip is : %s\n", inet_ntoa((struct in_addr)sockaddr_in__client_addr.sin_addr));

	
//	server_length = send((int)tcp_programmer_define_signed_int__connect__sockfd, (void *)"welcome !", (size_t)buffer_size, (int)0);
//	server_length = recv((int)tcp_programmer_define_signed_int__connect__sockfd, (void *)server_buffer, (size_t)buffer_size, (int)0);
//	printf("%s\n", server_buffer);
//
//	while(1)
//	{
//		server_length = recv(tcp_programmer_define_signed_int__connect__sockfd, (void *)server_buffer, buffer_size, 0);
//		if(server_length == -1)
//		{
//			printf("recv() failed !\n");
//			break;
//		}
//		printf("server has received data that is : %s\n", server_buffer);
//		if(!strcmp(server_buffer, "quit"))
//			break;
//	}
//
//
//	close(tcp_programmer_define_signed_int__listening_sockfd);
//	close(tcp_programmer_define_signed_int__connect__sockfd);
}



void tcp_send(void)
{
	tcp_programmer_define_unsigned_long__size_of_send = send((int)tcp_programmer_define_signed_int__connect__sockfd, (void *)tcp_programmer_define_unsigned_char_point__picture_buffer_out, (size_t)tcp_programmer_define_unsigned_long__size_of_out_picture_buffer, (int)0);

        if(tcp_programmer_define_unsigned_long__size_of_send == -1)
        {
                fprintf(stderr, "\nsend to client-capturer failed !\n");
                return;
        }
        else
        {
                printf("sended data which size is %ld\n", tcp_programmer_define_unsigned_long__size_of_recv);
        }

}



void tcp_receive(void)
{
	tcp_programmer_define_unsigned_long__size_of_recv = recv((int)tcp_programmer_define_signed_int__connect__sockfd, (void *)tcp_programmer_define_unsigned_char_point__picture_buffer_in, (size_t)TCP_PICTURE_WIDTH*TCP_PICTURE_HEIGHT*TCP_PICTURE_BIT_DEPTH/*sizeof(tcp_programmer_define_unsigned_char_point__picture_buffer_in)*/, (int)0);

	if(tcp_programmer_define_unsigned_long__size_of_recv == -1)
        {
                fprintf(stderr, "\nreceive from client-capturer failed !\n");
                return;
        }
        else
        {
                printf("received data which size is %ld\n", tcp_programmer_define_unsigned_long__size_of_recv);
	}
}



void tcp_quit(void)
{
	fprintf(stdout, "quiting tcp communication:\n\t......\n");
	if(!(close(tcp_programmer_define_signed_int__listening_sockfd)) && !(close(tcp_programmer_define_signed_int__connect__sockfd)))
		fprintf(stdout, "\tsuccessful !\n");
	else
		fprintf(stdout, "\tfailed ! -> close();\n");

}
















