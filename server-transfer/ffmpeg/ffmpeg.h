/*
 * =================================================================================================
 * ffmpeg.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_FFMPEG
#define PROGRAMMER_DEFINE_FFMPEG

#include "../common/common.h"

#define SUCCESS 0
#define FAILURE -1

#define FFMPEG_PICTURE_WIDTH PICTURE_WIDTH
#define FFMPEG_PICTURE_HEIGHT PICTURE_HEIGHT
#define FFMPEG_PICTURE_BIT_DEPTH PICTURE_BIT_DEPTH

extern unsigned char *ffmpeg_programmer_define_unsigned_char_point__picture_buffer;
extern unsigned long ffmpeg_programmer_define_unsigned_long__picture_size;


void ffmpeg_init(void);

void ffmpeg_picture_encode(void);

void ffmpeg_picture_decode(void);

void ffmpeg_quit(void);


#endif
