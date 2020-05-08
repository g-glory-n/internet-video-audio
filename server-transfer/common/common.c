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

#include "../network/tcp/tcp.h"
#include "../network/udp/udp.h"
#include "../ffmpeg/ffmpeg.old.h"
#include "../SDL2/SDL2.h"

void common_init(void)
{
	tcp_init();
//	udp_init();
	ffmpeg_old_decode_init();
//	ffmpeg_init();
	SDL2_init();
}

void common_refresh(void)
{
	tcp_receive();
//	udp_receive();
	ffmpeg_old_picture_decode();
//	ffmpeg_picture_decode();
	SDL2_refresh();
}


void common_quit(void)
{
	tcp_quit();
//	udp_quit();
//	ffmpeg_quit();
	ffmpeg_old_decode_quit();
	SDL2_quit();
}

