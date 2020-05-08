/*
 * =================================================================================================
 * udp.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_UDP_H
#define PROGRAMMER_DEFINE_UDP_H

#include "../../common/common.h"

#define UDP_PICTURE_WIDTH PICTURE_WIDTH
#define UDP_PICTURE_HEIGHT PICTURE_HEIGHT
#define UDP_PICTURE_BIT_DEPTH PICTURE_BIT_DEPTH

#define SUCCESS 0
#define FAILURE -1


extern unsigned char *udp_programmer_define_unsigned_char_point__picture_buffer;
extern unsigned long udp_programmer_define_unsigned_long__size_of_recv;



extern void udp_init(void);


extern void udp_send(void);


extern void udp_receive(void);


extern void udp_quit(void);




#endif
