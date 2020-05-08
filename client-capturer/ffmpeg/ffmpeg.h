/*
 * =================================================================================================
 * ffmpeg.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_FFMPEG_H
#define PROGRAMMER_DEFINE_FFMPEG_H

#include "../common/common.h"

#define FFMPEG_PICTURE_WIDTH PICTURE_WIDTH
#define FFMPEG_PICTURE_HEIGHT PICTURE_HEIGHT

#define SUCCESS 0
#define FAILURE -1

extern unsigned char *ffmpeg_programmer_define_unsigned_char_point__picture_buffer;

extern void ffmpeg_init(void);

extern void ffmpeg_picture_encode(void);

extern void ffmpeg_picture_decode(void);

extern void ffmpeg_quit(void);




#endif

