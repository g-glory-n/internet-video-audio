/*
 * =================================================================================================
 * udp.c
 * =================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "udp.h"


int udp_programmer_define_signed_int__connect_sockfd = 0;
struct sockaddr_in udp_sockaddr_in__server_sockaddr_in;
struct sockaddr_in udp_sockaddr_in__client_sockaddr_in;
socklen_t socklen_t__socksddr_param_length = 0;


unsigned char *udp_programmer_define_unsigned_char_point__picture_buffer = NULL;
unsigned long udp_programmer_define_unsigned_long__size_of_recv = 0;


void udp_init(void)
{
	udp_programmer_define_unsigned_char_point__picture_buffer = (unsigned char *)malloc(UDP_PICTURE_WIDTH*UDP_PICTURE_HEIGHT*UDP_PICTURE_BIT_DEPTH);
	(void *)memset((void *)&udp_sockaddr_in__server_sockaddr_in, (int)0, (size_t)sizeof(udp_sockaddr_in__server_sockaddr_in));
	(void *)memset((void *)&udp_sockaddr_in__client_sockaddr_in, (int)0, (size_t)sizeof(udp_sockaddr_in__client_sockaddr_in));

	udp_sockaddr_in__server_sockaddr_in.sin_family = (short int)AF_INET;
	udp_sockaddr_in__server_sockaddr_in.sin_port = (uint16_t)htons((uint16_t)1024);
	udp_sockaddr_in__server_sockaddr_in.sin_addr.s_addr = (uint32_t)htonl((uint32_t)INADDR_ANY);

	socklen_t__socksddr_param_length = (size_t)sizeof(struct sockaddr_in);

	udp_programmer_define_signed_int__connect_sockfd = (int)socket((int)AF_INET, (int)SOCK_DGRAM, (int)0);

	bind((int)udp_programmer_define_signed_int__connect_sockfd, (struct sockaddr *)&udp_sockaddr_in__server_sockaddr_in, sizeof(udp_sockaddr_in__server_sockaddr_in));
	
}


void udp_send(void)
{
	
}


void udp_receive(void)
{
	udp_programmer_define_unsigned_long__size_of_recv = recvfrom((int)udp_programmer_define_signed_int__connect_sockfd, (void *)udp_programmer_define_unsigned_char_point__picture_buffer, (size_t)UDP_PICTURE_WIDTH*UDP_PICTURE_HEIGHT*UDP_PICTURE_BIT_DEPTH, 0, (struct sockaddr *)&udp_sockaddr_in__client_sockaddr_in, (socklen_t *)&socklen_t__socksddr_param_length);

//对于sendto()函数, 成功则返回实际传送出去的字符数，失败返回-1, 错误原因存于errno中
//对于recvfrom()函数, 成功则返回接收到的字符数，失败则返回-1, 错误原因存于errno中
	if(udp_programmer_define_unsigned_long__size_of_recv == -1)
	{
		fprintf(stderr, "\nreceive from client-capturer failed !\n");
		return;
	}
	else
	{
		printf("received a data which size is %ld\n", udp_programmer_define_unsigned_long__size_of_recv);
	}
}


void udp_quit(void)
{
	
}
