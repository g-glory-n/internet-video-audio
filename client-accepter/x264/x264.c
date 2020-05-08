#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>

#include <x264.h>

#include "x264.h"
#include "../v4l2/v4l2.h"

/*
 * =================================================================================================
 * the data structure of encoding picture necessarily
 * =================================================================================================
*/
//int     x264_encoder_headers( x264_t *, x264_nal_t **pp_nal, int *pi_nal );
int x264_programmer_define_int__nal = 0;
x264_nal_t *x264_nal_t__point__nal = NULL;
x264_t *x264_t__point__handle = NULL;
x264_picture_t *x264_picture_t__point__in = NULL;
x264_picture_t *x264_picture_t__point__out = NULL;
x264_param_t *x264_param_t__point__param = NULL;

/*
 * =================================================================================================
 * can be called for other program 
 * =================================================================================================
*/
unsigned char *x264_programmer_define_unsigned_char_point__picture_buffer = NULL;
unsigned long x264_programmer_define_unsigned_long__after_x264_size = 0;

/*
 * =================================================================================================
 * the necessary data point of separating YUYV
 * =================================================================================================
*/
unsigned char *x264_programmer_define_unsigned_char_point__picture_Y = NULL;
unsigned char *x264_programmer_define_unsigned_char_point__picture_U = NULL;
unsigned char *x264_programmer_define_unsigned_char_point__picture_V = NULL;

void x264_init(void)
{
	x264_picture_t__point__in = (x264_picture_t *)malloc(sizeof(x264_picture_t));
	x264_picture_t__point__out = (x264_picture_t *)malloc(sizeof(x264_picture_t));
	x264_param_t__point__param = (x264_param_t *)malloc(sizeof(x264_param_t));
	x264_programmer_define_unsigned_char_point__picture_buffer = (unsigned char *)malloc(V4L2_PICTURE_WIDTH*V4L2_PICTURE_HEIGHT*2);


	
	
	
/*
 * =================================================================================================
 * set the x264 encode param
 * =================================================================================================
*/	
//	x264_param_default(x264_param_t__point__param);
        /*
        x264_param_t__point__param->i_log_level  = X264_LOG_DEBUG;
        x264_param_t__point__param->i_threads  = X264_SYNC_LOOKAHEAD_AUTO;
        x264_param_t__point__param->i_frame_total = 0;
        x264_param_t__point__param->i_keyint_max = 10;
        x264_param_t__point__param->i_bframe  = 5;
        x264_param_t__point__param->b_open_gop  = 0;
        x264_param_t__point__param->i_bframe_pyramid = 0;
        x264_param_t__point__param->rc.i_qp_constant=0;
        x264_param_t__point__param->rc.i_qp_max=0;
        x264_param_t__point__param->rc.i_qp_min=0;
        x264_param_t__point__param->i_bframe_adaptive = X264_B_ADAPT_TRELLIS;
        x264_param_t__point__param->i_fps_den  = 1;
        x264_param_t__point__param->i_fps_num  = 25;
        x264_param_t__point__param->i_timebase_den = pParam->i_fps_num;
        x264_param_t__point__param->i_timebase_num = pParam->i_fps_den;
        */

	x264_param_default_preset(x264_param_t__point__param, "fast" , "zerolatency" ); //实时编码必须
	x264_param_t__point__param->i_width = X264_PICTURE_WIDTH;
	x264_param_t__point__param->i_height = X264_PICTURE_HEIGHT;
	x264_param_t__point__param->i_csp = X264_CSP_I422;
        x264_param_t__point__param->i_fps_den  = 1;
        x264_param_t__point__param->i_fps_num  = 30;
	
//	x264_param_t__point__param->i_threads = 1; //并行编码多帧 the larger the number, the faster
	x264_param_t__point__param->i_threads = 8; //并行编码多帧 the larger the number, the faster
	x264_param_t__point__param->rc.b_mb_tree = 0; //实时编码必须为0，否则有延迟
	
	x264_param_t__point__param->i_keyint_max = 30; //?
	x264_param_t__point__param->b_intra_refresh = 1; //?
	x264_param_t__point__param->b_annexb = 1; //?

//	x264_param_apply_profile(x264_param_t__point__param, "baseline"); //编码器的参数, x264 [error]: baseline profile doesn't support 4:2:2
	x264_param_apply_profile(x264_param_t__point__param, x264_profile_names[4]); //static const char * const x264_profile_names[] = { "baseline", "main", "high", "high10", "high422", "high444", 0 };
	







	x264_t__point__handle = x264_encoder_open(x264_param_t__point__param);

	x264_picture_init(x264_picture_t__point__out); //?x264_picture_init
	x264_picture_alloc(x264_picture_t__point__in, X264_CSP_I422, x264_param_t__point__param->i_width, x264_param_t__point__param->i_height);
	
	x264_programmer_define_unsigned_char_point__picture_Y = x264_picture_t__point__in->img.plane[0];
	x264_programmer_define_unsigned_char_point__picture_U = x264_picture_t__point__in->img.plane[1];
	x264_programmer_define_unsigned_char_point__picture_V = x264_picture_t__point__in->img.plane[2];
}

void x264_picture_encode(void)
{

	unsigned long x264_programmer_define_unsigned_long__for_i0 = 0;
	unsigned long x264_programmer_define_unsigned_long__picture_size = X264_PICTURE_WIDTH*X264_PICTURE_HEIGHT*2;
	unsigned long x264_programmer_define_unsigned_long__index_Y = 0;
	unsigned long x264_programmer_define_unsigned_long__index_U = 0;
	unsigned long x264_programmer_define_unsigned_long__index_V = 0;

/*
 * =================================================================================================
 * separate "Y U V" data of YUYV to x264_picture_t__point__in->img.plane["0 1 2"]
 * =================================================================================================
*/
	memcpy(x264_programmer_define_unsigned_char_point__picture_buffer, (unsigned char *)v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].start, V4L2_PICTURE_WIDTH*V4L2_PICTURE_HEIGHT*2);
	for(x264_programmer_define_unsigned_long__for_i0 = 0;x264_programmer_define_unsigned_long__for_i0 < x264_programmer_define_unsigned_long__picture_size; x264_programmer_define_unsigned_long__for_i0 = x264_programmer_define_unsigned_long__for_i0 + 4)
	{
		x264_programmer_define_unsigned_char_point__picture_Y[x264_programmer_define_unsigned_long__index_Y++] = x264_programmer_define_unsigned_char_point__picture_buffer[x264_programmer_define_unsigned_long__for_i0 + 0];
		x264_programmer_define_unsigned_char_point__picture_U[x264_programmer_define_unsigned_long__index_U++] = x264_programmer_define_unsigned_char_point__picture_buffer[x264_programmer_define_unsigned_long__for_i0 + 1];
		x264_programmer_define_unsigned_char_point__picture_Y[x264_programmer_define_unsigned_long__index_Y++] = x264_programmer_define_unsigned_char_point__picture_buffer[x264_programmer_define_unsigned_long__for_i0 + 2];
		x264_programmer_define_unsigned_char_point__picture_V[x264_programmer_define_unsigned_long__index_V++] = x264_programmer_define_unsigned_char_point__picture_buffer[x264_programmer_define_unsigned_long__for_i0 + 3];
	}


	static unsigned long x264_ulong_i_pts = 0;
	x264_picture_t__point__in->i_pts = x264_ulong_i_pts++; //?x264_ulong_i_pts++
	x264_picture_t__point__in->i_type = X264_TYPE_AUTO; //?X264_TYPE_AUTO

	if(x264_encoder_encode(x264_t__point__handle, &x264_nal_t__point__nal, &x264_programmer_define_int__nal, x264_picture_t__point__in, x264_picture_t__point__out) == -1)
	{
		printf("\nencode picture failed ! -> x264_encoder_encode();\n");
		exit(FAILURE);
	}


/*
 * =================================================================================================
 * write to memory
 * =================================================================================================
*/
	unsigned long x264_programmer_define_unsigned_long__for_i1 = 0;
	x264_programmer_define_unsigned_long__after_x264_size = 0;
	unsigned char *x264_programmer_define_unsigned_char_point__picture_buffer_copy = x264_programmer_define_unsigned_char_point__picture_buffer;
	for (x264_programmer_define_unsigned_long__for_i1 = 0; x264_programmer_define_unsigned_long__for_i1 < x264_programmer_define_int__nal; x264_programmer_define_unsigned_long__for_i1++) 
	{
		memcpy(x264_programmer_define_unsigned_char_point__picture_buffer_copy, x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i1].p_payload, x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i1].i_payload);   
		x264_programmer_define_unsigned_char_point__picture_buffer_copy += x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i1].i_payload;
		x264_programmer_define_unsigned_long__after_x264_size += x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i1].i_payload;
	}


/*
 * =================================================================================================
 * write to file
 * =================================================================================================
*/
/*
	unsigned long x264_programmer_define_unsigned_long__for_i1 = 0;
	for (x264_programmer_define_unsigned_long__for_i1 = 0; x264_programmer_define_unsigned_long__for_i1 < x264_programmer_define_int__nal; x264_programmer_define_unsigned_long__for_i1++)
	{
        	fwrite(x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i1].p_payload, 1, x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i1].i_payload, fp_filename);
        }
*/

	printf("picture size after x264 encode: %ld Byte\n", x264_programmer_define_unsigned_long__after_x264_size);
}


void x264_quit(void)
{
/*
 * =================================================================================================
 * flush encoder
 * =================================================================================================
*/
        printf("\nflushing frame of x264:\n......\n");  
	unsigned long x264_programmer_define_unsigned_long__return_from_x264_encoder_encode = 0;
	unsigned long x264_programmer_define_unsigned_long__for_i0 = 0;
	x264_programmer_define_unsigned_long__after_x264_size = 0;
	unsigned char *x264_programmer_define_unsigned_char_point__picture_buffer_copy = x264_programmer_define_unsigned_char_point__picture_buffer;
        while(1)
	{ 
		x264_programmer_define_unsigned_long__after_x264_size = 0;
		x264_programmer_define_unsigned_long__return_from_x264_encoder_encode = x264_encoder_encode(x264_t__point__handle, &x264_nal_t__point__nal, &x264_programmer_define_int__nal, NULL, x264_picture_t__point__out);
                if(x264_programmer_define_unsigned_long__return_from_x264_encoder_encode == 0)
                	break;
		for (x264_programmer_define_unsigned_long__for_i0 = 0; x264_programmer_define_unsigned_long__for_i0 < x264_programmer_define_int__nal; x264_programmer_define_unsigned_long__for_i0++) 
		{
			memcpy(x264_programmer_define_unsigned_char_point__picture_buffer_copy, x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i0].p_payload, x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i0].i_payload);   
			x264_programmer_define_unsigned_char_point__picture_buffer_copy += x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i0].i_payload;
			x264_programmer_define_unsigned_long__after_x264_size += x264_nal_t__point__nal[x264_programmer_define_unsigned_long__for_i0].i_payload;
		}
/*
 * =================================================================================================
 * need to send to inetrnet or display to screen
 * =================================================================================================
*/
		printf("picture size after x264 encode: %ld Byte\n", x264_programmer_define_unsigned_long__after_x264_size);

        }
	printf("successfully !\nflushed frame of x264 !\n\n");

	x264_encoder_close(x264_t__point__handle);
	x264_picture_clean(x264_picture_t__point__in);
	
	free(x264_picture_t__point__in);
	free(x264_picture_t__point__out);
	free(x264_param_t__point__param);
	free(x264_programmer_define_unsigned_char_point__picture_buffer);
}
