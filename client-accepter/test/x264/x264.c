#include <stdint.h>
#include <x264.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>

#define X264_PICTURE_WIDTH 640
#define X264_PICTURE_HEIGHT 480
#define FAILURE -1
#define SUCCESS 0

int x264_number_nal = 0;
x264_nal_t *x264_nal = NULL;
x264_t *x264_handle = NULL;
x264_picture_t *x264_picture_in = NULL;
x264_picture_t *x264_picture_out = NULL;
x264_param_t *x264_param = NULL;

unsigned char *x264_picture_buffer = NULL;

unsigned char *x264_picture_Y = NULL;
unsigned char *x264_picture_U = NULL;
unsigned char *x264_picture_V = NULL;

unsigned long x264_number_for_i = 0;
unsigned long x264_number_picture_size = X264_PICTURE_WIDTH*X264_PICTURE_HEIGHT*2 - 4;

extern void x264_init(void);
extern void x264_picture_encode(void);
extern void x264_picture_decode(void);
extern void x264_quit(void);

FILE *fp2 = NULL;
int main(int argc, char *argv[])
{
	x264_init();
void x264_init();
  
	FILE *fp1 = NULL;
	fp1 = fopen("./standard_picture", "rb");
	fread(x264_picture_buffer, X264_PICTURE_WIDTH*X264_PICTURE_HEIGHT*2, 1, fp1);

	x264_picture_encode();

	x264_quit();
	fclose(fp2);
	return 0;
}


void x264_init(void)
{
	fp2 = fopen("./x264_encode_picture", "wb");

	x264_picture_in = (x264_picture_t *)malloc(sizeof(x264_picture_t));
	x264_picture_out = (x264_picture_t *)malloc(sizeof(x264_picture_t));
	x264_param = (x264_param_t *)malloc(sizeof(x264_param_t));
	x264_picture_buffer = (unsigned char *)malloc(X264_PICTURE_WIDTH*X264_PICTURE_HEIGHT*2);

	x264_param_default(x264_param);
        /*
        x264_Param->i_log_level  = X264_LOG_DEBUG;
        x264_Param->i_threads  = X264_SYNC_LOOKAHEAD_AUTO;
        x264_Param->i_frame_total = 0;
        x264_Param->i_keyint_max = 10;
        x264_Param->i_bframe  = 5;
        x264_Param->b_open_gop  = 0;
        x264_Param->i_bframe_pyramid = 0;
        x264_Param->rc.i_qp_constant=0;
        x264_Param->rc.i_qp_max=0;
        x264_Param->rc.i_qp_min=0;
        x264_Param->i_bframe_adaptive = X264_B_ADAPT_TRELLIS;
        x264_Param->i_fps_den  = 1;
        x264_Param->i_fps_num  = 25;
        x264_Param->i_timebase_den = pParam->i_fps_num;
        x264_Param->i_timebase_num = pParam->i_fps_den;
        */
	x264_param->i_width = X264_PICTURE_WIDTH;
	x264_param->i_height = X264_PICTURE_HEIGHT;
//	x264_param->rc.i_lookahead = 0;
//	x264_param->i_fps_num = 30;
//	x264_param->i_fps_den = 1;
	x264_param->i_csp = X264_CSP_I422;
//	x264_param->i_fps_den = 1;
//	x264_param->i_fps_num = 30;
	x264_param_apply_profile(x264_param, x264_profile_names[4]); //?x264_profile_names
	
	x264_handle = x264_encoder_open(x264_param);

	x264_picture_init(x264_picture_out); //?x264_picture_init
	x264_picture_alloc(x264_picture_in, X264_CSP_I422, x264_param->i_width, x264_param->i_height);
	
	x264_picture_Y = x264_picture_in->img.plane[0];
	x264_picture_U = x264_picture_in->img.plane[1];
	x264_picture_V = x264_picture_in->img.plane[2];
}

void x264_picture_encode(void)
{
	static unsigned long x264_number_picture_in_i_pts = 0;
	unsigned long x264_number_index_Y = 0;
	unsigned long x264_number_index_U = 0;
	unsigned long x264_number_index_V = 0;
//	memcpy(x264_picture_buffer, (unsigned char *)v4l2_picture_buffer[v4l2_queue_buffer.index].start, X264_PICTURE_WIDTH*X264_PICTURE_HEIGHT*2);
	for(x264_number_for_i = 0;x264_number_for_i < x264_number_picture_size; x264_number_for_i = x264_number_for_i + 4)
	{
		x264_picture_Y[x264_number_index_Y++] = x264_picture_buffer[x264_number_for_i + 0];
		x264_picture_U[x264_number_index_U++] = x264_picture_buffer[x264_number_for_i + 1];
		x264_picture_Y[x264_number_index_Y++] = x264_picture_buffer[x264_number_for_i + 2];
		x264_picture_V[x264_number_index_V++] = x264_picture_buffer[x264_number_for_i + 3];
	}
	x264_picture_in->i_pts = x264_number_picture_in_i_pts++;

//	static long int pts = 0;
//	x264_picture_in->i_pts = pts++;

//	x264_picture_in->i_type = X264_TYPE_AUTO;
	if(x264_encoder_encode(x264_handle, &x264_nal, &x264_number_nal, x264_picture_in, x264_picture_out) == -1)
	{
		printf("\nencode picture failed ! -> x264_encoder_encode();\n");
		exit(FAILURE);
	}



//	int i = 0;
//	for (i = 0; i < x264_number_nal; i++) {
//		memcpy(x264_p_out, x264_nal[i].p_payload, x264_nal[i].i_payload);   
//		x264_p_out += x264_nal[i].i_payload;								 
//		result += x264_nal[i].i_payload;
//	}
	
	int j = 0;
	for (j = 0; j < x264_number_nal; j++)
	{
        	fwrite(x264_nal[j].p_payload, 1, x264_nal[j].i_payload, fp2);
        }

}

void x264_picture_decode(void)
{
	
}

void x264_quit(void)
{
	x264_picture_clean(x264_picture_in);
	x264_encoder_close(x264_handle);
	
	free(x264_picture_in);
	free(x264_picture_out);
	free(x264_param);
}
