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
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "../../v4l2/v4l2.h"
#include "../../x264/x264.h"
#include "../../x265/x265.h"
#include "../../ffmpeg/ffmpeg.old.h"
#include "../../ffmpeg/ffmpeg.h"
#include "udp.h"

int udp_programmer_define_signed_int__connect_sockfd = 0;//int file-descriptor
struct sockaddr_in udp_sockaddr_in__server_addr;

unsigned char *udp_programmer_define_unsigned_char_point__picture_buffer = NULL;
unsigned long udp_programmer_define_unsigned_long_point__compressed_size = 0;
unsigned long udp_programmer_define_unsigned_long__size_of_send = 0;

void udp_init(void)
{
/*
 * =================================================================================================
 * point to the compressed buffer and size
 * =================================================================================================
*/
	udp_programmer_define_unsigned_char_point__picture_buffer = x264_programmer_define_unsigned_char_point__picture_buffer;
	udp_programmer_define_unsigned_long_point__compressed_size = x264_programmer_define_unsigned_long__after_x264_size;


/*
 * =================================================================================================
 * set the params of socket
 * =================================================================================================
*/
	(void *)memset((void *)&udp_sockaddr_in__server_addr, (int)0, (size_t)sizeof(udp_sockaddr_in__server_addr));
	udp_sockaddr_in__server_addr.sin_family = AF_INET;
	udp_sockaddr_in__server_addr.sin_port = htons(1024);
	udp_sockaddr_in__server_addr.sin_addr.s_addr = inet_addr("192.168.1.150");

	udp_programmer_define_signed_int__connect_sockfd = (int)socket((int)AF_INET, (int)SOCK_DGRAM, (int)0);
	if(udp_programmer_define_signed_int__connect_sockfd == -1)
	{
		fprintf(stderr, "\ncreate socket failed ! -> socket();\n");
		exit(FAILURE);
	}
}


void udp_send(void)
{
//	char client_buffer[20] = "I am g-glory-n";
//	sendto((int)connect_sockfd, (const void *)client_buffer, (size_t)20, (int)0, (struct sockaddr *)&server_addr, (socklen_t)sizeof(server_addr));

/*
 * =================================================================================================
 * set the size of data, send and print the data
 * =================================================================================================
*/
	udp_programmer_define_unsigned_long_point__compressed_size = x264_programmer_define_unsigned_long__after_x264_size;
	udp_programmer_define_unsigned_long__size_of_send = sendto((int)udp_programmer_define_signed_int__connect_sockfd, (const void *)udp_programmer_define_unsigned_char_point__picture_buffer, (size_t)udp_programmer_define_unsigned_long_point__compressed_size, (int)0, (struct sockaddr *)&udp_sockaddr_in__server_addr, (socklen_t)sizeof(udp_sockaddr_in__server_addr));

	printf("sended data which size is %ld\n", udp_programmer_define_unsigned_long__size_of_send);
}


void udp_receive(void)
{
	
}


void udp_quit(void)
{
	
}



