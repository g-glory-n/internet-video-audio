/*
 * =================================================================================================
 * tcp.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_TCP_H
#define PROGRAMMER_DEFINE_TCP_H

#include "../../common/common.h"

#define TCP_PICTURE_WIDTH PICTURE_WIDTH
#define TCP_PICTURE_HEIGHT PICTURE_HEIGHT
#define TCP_PICTURE_BIT_DEPTH PICTURE_BIT_DEPTH

#define SUCCESS 0
#define FAILURE -1


extern unsigned char *tcp_programmer_define_unsigned_char_point__picture_buffer_in;
extern unsigned long tcp_programmer_define_unsigned_long__size_of_recv;

extern unsigned char *tcp_programmer_define_unsigned_char_point__picture_buffer_out;
extern unsigned long tcp_programmer_define_unsigned_long__size_of_send;


extern void tcp_init(void);


extern void tcp_send(void);


extern void tcp_receive(void);


extern void tcp_quit(void);




#endif
