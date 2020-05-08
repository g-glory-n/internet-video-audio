/*
 * =================================================================================================
 * main.c
 * =================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <linux/types.h>
#include <linux/videodev2.h>
#include <SDL2/SDL.h>

#include "../v4l2/v4l2.h"
#include "../SDL2/SDL2.h"
#include "common.h"
#include "../x264/x264.h"
#include "../x265/x265.h"

int main(int argc, char *argv[])
{
	unsigned int number = 0;
	char a = 0;

	common_init();

	while(1)
	{
		common_refresh();
		number++;
		if(number == 1000)
		{
			fscanf(stdin, "%c", &a);
			if(a == 'q')
				break;
			else
				number = 0;
		}
	}

	common_quit();
	exit(SUCCESS);
}
