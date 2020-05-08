/*
 * =================================================================================================
 * tcp.c
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

#include "../../v4l2/v4l2.h"
#include "../../x264/x264.h"
#include "../../x265/x265.h"
#include "../../ffmpeg/ffmpeg.old.h"
#include "../../ffmpeg/ffmpeg.h"
#include "tcp.h"


//signed int tcp_programmer_define_signed_int__server_sockfd = 0;
signed int tcp_programmer_define_signed_int__client_sockfd = 0;
struct sockaddr_in sockaddr_in__server_addr;
//struct sockaddr_in sockaddr_in__client_addr;


unsigned char *tcp_programmer_define_unsigned_char_point__picture_buffer = NULL;
unsigned long tcp_programmer_define_unsigned_long_point__compressed_size = 0;
unsigned long tcp_programmer_define_unsigned_long__size_of_send = 0;


void tcp_init(void)
{
	tcp_programmer_define_unsigned_char_point__picture_buffer = x264_programmer_define_unsigned_char_point__picture_buffer;
	tcp_programmer_define_unsigned_long_point__compressed_size = x264_programmer_define_unsigned_long__after_x264_size;


/*
 * =================================================================================================
 * initialize 
 * =================================================================================================
*/
	memset(&sockaddr_in__server_addr, 0, sizeof(sockaddr_in__server_addr));
//	memset(&client_addr, 0, sizeof(client_addr)); //initailization

/*
 * =================================================================================================
 * set the params of server_sockfd
 * =================================================================================================
*/
	sockaddr_in__server_addr.sin_family = AF_INET;
	sockaddr_in__server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockaddr_in__server_addr.sin_port = htons(1024);

	if((tcp_programmer_define_signed_int__client_sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket failed");
		exit(FAILURE);
	}

	if(connect(tcp_programmer_define_signed_int__client_sockfd, (struct sockaddr *)&sockaddr_in__server_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("connect failed");
		exit(FAILURE);
	}

//	printf("client ip is : %s\n"/*, inet_ntoa(client_addr.sin_addr)*/, inet_ntoa(sockaddr_in__server_addr.sin_addr));
//	printf("server ip is %s\n", inet_ntoa(sockaddr_in__server_addr.sin_addr));
//	length = recv((int)tcp_programmer_define_signed_int__client_sockfd, (void *)client_buffer, (size_t)buffer_size, (int)0);
//	length = send((int)tcp_programmer_define_signed_int__client_sockfd, (void *)"welcome !", (size_t)buffer_size, (int)0);

}



void tcp_send(void)
{
	tcp_programmer_define_unsigned_long_point__compressed_size = x264_programmer_define_unsigned_long__after_x264_size;

/*
 * =================================================================================================
 * send data to server
 * =================================================================================================
*/
	tcp_programmer_define_unsigned_long__size_of_send = send((int)tcp_programmer_define_signed_int__client_sockfd, (void *)tcp_programmer_define_unsigned_char_point__picture_buffer, (size_t)tcp_programmer_define_unsigned_long_point__compressed_size, (int)0);

	printf("sended data which size is %ld\n", tcp_programmer_define_unsigned_long__size_of_send);

}



void tcp_receive(void)
{
/*
 * =================================================================================================
 * receive data from server
 * =================================================================================================
*/
//	recv((int)tcp_programmer_define_signed_int__client_sockfd, (void *)client_buffer, (size_t)buffer_size, (int)0);


}



void tcp_quit(void)
{
	close(tcp_programmer_define_signed_int__client_sockfd);


}
