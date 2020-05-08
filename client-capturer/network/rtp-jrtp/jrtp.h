/*
 * =================================================================================================
 * rtp.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_RTP_H
#define PROGRAMMER_DEFINE_RTP_H

#include "../../common/common.h"

#define RTP_PICTURE_WIDTH PICTURE_WIDTH
#define RTP_PiCTURE_HEIGHT PICTURE_HEIGHT

#define SUCCESS 0
#define FAILURE -1

extern unsigned char *rtp_programmer_define_unsigned_char_point__picture_buffer;
extern unsigned long rtp_programmer_define_unsigned_long_point__compressed_size;
extern unsigned long rtp_programmer_define_unsigned_long__size_of_send;



static void rtp_check_error(int);

extern void rtp_init(void);

extern void rtp_send(void);

extern void rtp_receive(void);


extern void rtp_quit(void);










#endif



