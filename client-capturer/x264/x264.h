/*
 * =================================================================================================
 * x264.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_X264_H
#define PROGRAMMER_DEFINE_X264_H

#include "../common/common.h"

#define X264_PICTURE_WIDTH PICTURE_WIDTH
#define X264_PICTURE_HEIGHT PICTURE_HEIGHT

#define SUCCESS 0
#define FAILURE -1

extern unsigned char *x264_programmer_define_unsigned_char_point__picture_buffer;
extern unsigned long x264_programmer_define_unsigned_long__after_x264_size;


extern void x264_init(void);

extern void x264_picture_encode(void);

extern void x264_quit(void);


#endif

