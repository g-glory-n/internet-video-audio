/*
 * =================================================================================================
 * x265.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_X265_H
#define PROGRAMMER_DEFINE_X265_H

#include "../common/common.h"

#define X265_PICTURE_WIDTH PICTURE_WIDTH
#define X265_PICTURE_HEIGHT PICTURE_HEIGHT

#define SUCCESS 0
#define FAILURE -1

extern unsigned char *x265_programmer_define_unsigned_char_point__picture_buffer;
extern unsigned long x265_programmer_define_unsigned_long__after_x265_size;


extern void x265_init(void);

extern void x265_picture_encode(void);

extern void x265_quit(void);





#endif
