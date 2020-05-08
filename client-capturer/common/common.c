/*
 * =================================================================================================
 * common.c
 * =================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include "../v4l2/v4l2.h"
#include "../SDL2/SDL2.h"
#include "../x264/x264.h"
#include "../x265/x265.h"
#include "../ffmpeg/ffmpeg.old.h"
#include "../ffmpeg/ffmpeg.h"
#include "../network/tcp/tcp.h"
#include "../network/udp/udp.h"
#include "../network/rtp-jrtp/jrtp.h"
#include "common.h"

void common_init(void)
{
	v4l2_init();

	x264_init();
//	x265_init();
//	ffmpeg_old_encode_init();
//	ffmpeg_old_decode_init();
//	ffmpeg_old_init();
//	ffmpeg_init();

	tcp_init();
//	udp_init();
//	rtp_init();


//	SDL2_init();
}

void common_refresh(void)
{
	v4l2_refresh();

	x264_picture_encode();
//	x265_picture_encode();
//	ffmpeg_old_picture_encode();
//	ffmpeg_old_picture_decode();

	tcp_send();
//	udp_send();
//	rtp_send();


//	SDL2_refresh();
}


void common_quit(void)
{
	v4l2_quit();

	x264_quit();
//	x265_quit();
//	ffmpeg_old_encode_quit();
//	ffmpeg_old_decode_quit();
//	ffmpeg_old_quit();

	tcp_quit();
//	udp_quit();
//	rtp_quit();


//	SDL2_quit();
}



