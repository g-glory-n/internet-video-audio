/*
 * =================================================================================================
 * h264_encode.h
 * =================================================================================================
*/


#ifndef RK3399PRO_H264_H
#define RK3399PRO_H264_H

#include "../common/common.h"

#define RK3399PRO_PICTURE_WIDTH PICTURE_WIDTH
#define RK3399PRO_PICTURE_HEIGHT PICTURE_HEIGHT

#define SUCCESS 0
#define FAILURE -1


extern struct rk3399pro__frame_in
{
        extern unsigned char *rk3399pro__pchar__frame_in;
        extern unsigned long rk3399pro__ulong__frame_size_in;
};


extern struct rk3399pro__frame_out
{
	extern unsigned char *rk3399pro__pchar__frame_out;
	extern unsigned long rk3399pro__ulong__frame_size_out;
};



typedef struct {
	// global flow control flag
	RK_U32 frm_eos;
	RK_U32 pkt_eos;
	RK_U32 frame_count;
	RK_U64 stream_size;
	
	// src and dst
//	FILE *fp_input;
//	FILE *fp_output;
//	extern struct rk3399pro__frame_in rk3399pro__struct__frame_out;
//	extern struct rk3399pro__frame_out rk3399pro__struct__frame_out;
	extern unsigned char *rk3399pro__puchar__frame_in;
	extern unsigned char *rk3399pro__puchar__frame_out;
	
	// base flow context
	MppCtx ctx;
	MppApi *mpi;
	MppEncPrepCfg prep_cfg;
	MppEncRcCfg rc_cfg;
	MppEncCodecCfg codec_cfg;
	
	// input / output
	MppBuffer frm_buf;
	MppEncSeiMode sei_mode;
	
	// paramter for resource malloc
	RK_U32 width;
	RK_U32 height;
	RK_U32 hor_stride;
	RK_U32 ver_stride;
	MppFrameFormat fmt;
	MppCodingType type;
	RK_U32 num_frames;
	
	// resources
	size_t frame_size;
	/* NOTE: packet buffer may overflow */
	size_t packet_size;
	
	// rate control runtime parameter
	RK_S32 gop;
	RK_S32 fps;
	RK_S32 bps;
} rk3399pro__mpi_encode_data;


typedef struct {
//	char		file_input[MAX_FILE_NAME_LENGTH];
//	char		file_output[MAX_FILE_NAME_LENGTH];


	MppCodingType   type;
	RK_U32          width;
	RK_U32          height;
	MppFrameFormat  format;
	RK_U32          debug;
	RK_U32          num_frames;
	
	RK_U32          have_input;
	RK_U32          have_output;
} rk3399pro__mpi_encode_cmd;



extern MPP_RET rk3399pro__ctx_init(rk3399pro__mpi_encode_data **, rk3399pro__mpi_encode_cmd *);
extern MPP_RET rk3399pro__mpp_setup(rk3399pro__mpi_encode_data *);
extern MPP_RET test_mpp_run(rk3399pro__mpi_encode_data *);


extern void rk3399pro__h264_init(void);


extern void rk3399pro__h264_encode(void);


extern void rk3399pro__h264_decode(void);


extern void rk3399pro__h264_quit(void);







#endif





