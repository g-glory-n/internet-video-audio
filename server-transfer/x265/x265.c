#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>

#include <x265.h>

#include "x265.h"
#include "../v4l2/v4l2.h"

/*
 * =================================================================================================
 * the data structure of encoding picture necessarily
 * =================================================================================================
*/
//int x265_encoder_encode(x265_encoder *encoder, x265_nal **pp_nal, uint32_t *pi_nal, x265_picture *pic_in, x265_picture *pic_out);
uint32_t x265_programmer_define_int__nal = 0;
x265_nal *x265_nal__point__nal = NULL;
x265_encoder *x265_encoder__point__handle = NULL;
x265_picture *x265_picture__point__in = NULL;
//x265_picture *x265_picture__point__out = NULL;
x265_param *x265_param__point__param = NULL;

/*
 * =================================================================================================
 * can be called for other program 
 * =================================================================================================
*/
unsigned char *x265_programmer_define_unsigned_char_point__picture_buffer = NULL;
unsigned long x265_programmer_define_unsigned_long__after_x265_size = 0;

/*
 * =================================================================================================
 * the necessary data point of separating YUYV
 * =================================================================================================
*/
unsigned char *x265_programmer_define_unsigned_char_point__picture_Y = NULL;
unsigned char *x265_programmer_define_unsigned_char_point__picture_U = NULL;
unsigned char *x265_programmer_define_unsigned_char_point__picture_V = NULL;

void x265_init(void)
{
//	x265_picture__point__in = (x265_picture *)malloc(sizeof(x265_picture));
//	x265_picture__point__out = (x265_picture *)malloc(sizeof(x265_picture));
	x265_programmer_define_unsigned_char_point__picture_buffer = (unsigned char *)malloc(V4L2_PICTURE_WIDTH*V4L2_PICTURE_HEIGHT*2);

	x265_param__point__param = x265_param_alloc();
	x265_param_default(x265_param__point__param);
	x265_param__point__param->sourceWidth = X265_PICTURE_WIDTH;
        x265_param__point__param->sourceHeight = X265_PICTURE_HEIGHT;
        x265_param__point__param->internalCsp = X265_CSP_I422;
	x265_param__point__param->bRepeatHeaders = 1;
	x265_param__point__param->fpsNum = 60;
	x265_param__point__param->fpsDenom = 1;
	x265_encoder__point__handle = x265_encoder_open(x265_param__point__param);

	x265_picture__point__in = x265_picture_alloc();
	x265_picture_init(x265_param__point__param, x265_picture__point__in); //?x265_picture_init
	
	x265_programmer_define_unsigned_char_point__picture_Y = (unsigned char *)malloc(V4L2_PICTURE_WIDTH*V4L2_PICTURE_HEIGHT*2);
	x265_programmer_define_unsigned_char_point__picture_U = (unsigned char *)malloc(V4L2_PICTURE_WIDTH*V4L2_PICTURE_HEIGHT*2);
	x265_programmer_define_unsigned_char_point__picture_V = (unsigned char *)malloc(V4L2_PICTURE_WIDTH*V4L2_PICTURE_HEIGHT*2);
	x265_picture__point__in->planes[0] = x265_programmer_define_unsigned_char_point__picture_Y;
	x265_picture__point__in->planes[1] = x265_programmer_define_unsigned_char_point__picture_U;
	x265_picture__point__in->planes[2] = x265_programmer_define_unsigned_char_point__picture_V;

	x265_picture__point__in->stride[0] = X265_PICTURE_WIDTH;
	x265_picture__point__in->stride[1] = X265_PICTURE_WIDTH;
	x265_picture__point__in->stride[2] = X265_PICTURE_WIDTH;
}

void x265_picture_encode(void)
{

	unsigned long x265_programmer_define_unsigned_long__for_i0 = 0;
	unsigned long x265_programmer_define_unsigned_long__picture_size = X265_PICTURE_WIDTH*X265_PICTURE_HEIGHT*2;
	unsigned long x265_programmer_define_unsigned_long__index_Y = 0;
	unsigned long x265_programmer_define_unsigned_long__index_U = 0;
	unsigned long x265_programmer_define_unsigned_long__index_V = 0;

/*
 * =================================================================================================
 * separate "Y U V" data of YUYV to x265_picture__point__in->img.plane["0 1 2"]
 * =================================================================================================
*/
	memcpy(x265_programmer_define_unsigned_char_point__picture_buffer, (unsigned char *)v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].start, V4L2_PICTURE_WIDTH*V4L2_PICTURE_HEIGHT*2);
	for(x265_programmer_define_unsigned_long__for_i0 = 0;x265_programmer_define_unsigned_long__for_i0 < x265_programmer_define_unsigned_long__picture_size; x265_programmer_define_unsigned_long__for_i0 = x265_programmer_define_unsigned_long__for_i0 + 4)
	{
		x265_programmer_define_unsigned_char_point__picture_Y[x265_programmer_define_unsigned_long__index_Y++] = x265_programmer_define_unsigned_char_point__picture_buffer[x265_programmer_define_unsigned_long__for_i0 + 0];
		x265_programmer_define_unsigned_char_point__picture_U[x265_programmer_define_unsigned_long__index_U++] = x265_programmer_define_unsigned_char_point__picture_buffer[x265_programmer_define_unsigned_long__for_i0 + 1];
		x265_programmer_define_unsigned_char_point__picture_Y[x265_programmer_define_unsigned_long__index_Y++] = x265_programmer_define_unsigned_char_point__picture_buffer[x265_programmer_define_unsigned_long__for_i0 + 2];
		x265_programmer_define_unsigned_char_point__picture_V[x265_programmer_define_unsigned_long__index_V++] = x265_programmer_define_unsigned_char_point__picture_buffer[x265_programmer_define_unsigned_long__for_i0 + 3];
	}


	static unsigned long x265_ulong_i_pts = 0;
	x265_picture__point__in->pts = x265_ulong_i_pts++; //?x265_ulong_i_pts++

	if(x265_encoder_encode(x265_encoder__point__handle, &x265_nal__point__nal, &x265_programmer_define_int__nal, x265_picture__point__in, NULL/*x265_picture__point__out*/) == -1)
	{
		printf("\nencode picture failed ! -> x265_encoder_encode();\n");
		exit(FAILURE);
	}


/*
 * =================================================================================================
 * write to memory
 * =================================================================================================
*/
	unsigned long x265_programmer_define_unsigned_long__for_i1 = 0;
	x265_programmer_define_unsigned_long__after_x265_size = 0;
	unsigned char *x265_programmer_define_unsigned_char_point__picture_buffer_copy = x265_programmer_define_unsigned_char_point__picture_buffer;
	for (x265_programmer_define_unsigned_long__for_i1 = 0; x265_programmer_define_unsigned_long__for_i1 < x265_programmer_define_int__nal; x265_programmer_define_unsigned_long__for_i1++) 
	{
		memcpy(x265_programmer_define_unsigned_char_point__picture_buffer_copy, x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i1].payload, x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i1].sizeBytes);   
		x265_programmer_define_unsigned_char_point__picture_buffer_copy += x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i1].sizeBytes;
		x265_programmer_define_unsigned_long__after_x265_size += x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i1].sizeBytes;
	}


/*
 * =================================================================================================
 * write to file
 * =================================================================================================
*/
/*
	unsigned long x265_programmer_define_unsigned_long__for_i1 = 0;
	for (x265_programmer_define_unsigned_long__for_i1 = 0; x265_programmer_define_unsigned_long__for_i1 < x265_programmer_define_int__nal; x265_programmer_define_unsigned_long__for_i1++)
	{
        	fwrite(x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i1].payload, 1, x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i1].sizeBytes, fp_filename);
        }
*/

	printf("picture size after x265 encode: %ld Byte\n", x265_programmer_define_unsigned_long__after_x265_size);
}


void x265_quit(void)
{
/*
 * =================================================================================================
 * flush encoder
 * =================================================================================================
*/
        printf("\nflushing frame of x265:\n......\n");  
	unsigned long x265_programmer_define_unsigned_long__return_from_x265_encoder_encode = 0;
	unsigned long x265_programmer_define_unsigned_long__for_i0 = 0;
	x265_programmer_define_unsigned_long__after_x265_size = 0;
	unsigned char *x265_programmer_define_unsigned_char_point__picture_buffer_copy = x265_programmer_define_unsigned_char_point__picture_buffer;
        while(1)
	{ 
		x265_programmer_define_unsigned_long__after_x265_size = 0;
		x265_programmer_define_unsigned_long__return_from_x265_encoder_encode = x265_encoder_encode(x265_encoder__point__handle, &x265_nal__point__nal, &x265_programmer_define_int__nal, NULL, NULL/*x265_picture__point__out*/);
                if(x265_programmer_define_unsigned_long__return_from_x265_encoder_encode == 0)
                	break;
		for (x265_programmer_define_unsigned_long__for_i0 = 0; x265_programmer_define_unsigned_long__for_i0 < x265_programmer_define_int__nal; x265_programmer_define_unsigned_long__for_i0++) 
		{
			memcpy(x265_programmer_define_unsigned_char_point__picture_buffer_copy, x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i0].payload, x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i0].sizeBytes);   
			x265_programmer_define_unsigned_char_point__picture_buffer_copy += x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i0].sizeBytes;
			x265_programmer_define_unsigned_long__after_x265_size += x265_nal__point__nal[x265_programmer_define_unsigned_long__for_i0].sizeBytes;
		}
/*
 * =================================================================================================
 * need to send to inetrnet or display to screen
 * =================================================================================================
*/
		printf("picture size after x265 encode: %ld Byte\n", x265_programmer_define_unsigned_long__after_x265_size);

        }
	printf("successfully !\nflushed frame of x265 !\n\n");

	x265_encoder_close(x265_encoder__point__handle);
	x265_picture_free(x265_picture__point__in);
	x265_param_free(x265_param__point__param);
	
//	free(x265_picture__point__in);
//	free(x265_picture__point__out);
	free(x265_programmer_define_unsigned_char_point__picture_buffer);
}
