/*
 * =================================================================================================
 * ffmpeg.old.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_FFMPEG_OLD_H
#define PROGRAMMER_DEFINE_FFMPEG_OLD_H

#include "../common/common.h"

#define FFMPEG_PICTURE_WIDTH PICTURE_WIDTH
#define FFMPEG_PICTURE_HEIGHT PICTURE_HEIGHT

#define SUCCESS 0
#define FAILURE -1

extern signed int ffmpeg_old_programmer_define_signed_int__size_after_ffmpeg_old;
extern unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_encode;

extern unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode;

extern void ffmpeg_old_init(void);
extern void ffmpeg_old_encode_init(void);
extern void ffmpeg_old_decode_init(void);

extern void ffmpeg_old_picture_encode(void);

extern void ffmpeg_old_picture_decode(void);

extern void ffmpeg_old_quit(void);
extern void ffmpeg_old_encode_quit(void);
extern void ffmpeg_old_decode_quit(void);



#endif
