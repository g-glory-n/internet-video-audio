/*
 * =================================================================================================
 * h264_encode.c
 * =================================================================================================
*/

//	接下来就是喂数据和拿输出数据的过程了，具体可以直接看sample代码，这里解释下一些基本概念，方便大家看Sample代码时候不懵逼。
//	
//	MppPacket  ：   存放编码数据，例如264、265数据
//	MppFrame  ：   存放解码的数据，例如YUV、RGB数据
//	MppTask    :     一次编码或者解码的session
//	
//	编码就是喂MppFrame，输出MppPacket；
//	解码就是喂MppPacket，输出MppFrame；
//	
//	MPI包含两套接口做编解码：
//	一套是简易接口， 类似 decode_put_packet / decode_get_frame 这样put/get即可
//	一套是高级接口， 类似 poll / enqueue/ dequeue 这样的对input output队列进行操作
//	
//	解码得到的output buffer一般都拥有虚拟地址和物理地址的fd，紧接着就可以通过RGA做对应操作或者拷贝，速度是相当快的


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>

#include "h264_encode.h"

#include "../v4l2/v4l2.h"

#include "include/rk_mpi.h"
#include "include/mpp_env.h"
#include "include/mpp_mem.h"
#include "include/mpp_log.h"
#include "include/mpp_time.h"
#include "include/mpp_common.h"
#include "include/utils.h"


/*
 * =================================================================================================
 * the data structure of encoding picture necessarily
 * =================================================================================================
*/
//rk3399pro__mpi_encode_cmd rk3399pro__struct__enc_cmd;
//rk3399pro__mpi_encode_cmd *rk3399pro__pstruct__enc_cmd = &rk3399pro__struct__enc_cmd;

//rk3399pro__mpi_encode_data rk3399pro__struct__enc_data;
//rk3399pro__mpi_encode_data *rk3399pro__pstruct__enc_data = &rk3399pro__struct__enc_data;
rk3399pro__mpi_encode_data *rk3399pro__pstruct__enc_data = NULL;

/*
 * =================================================================================================
 * can be called for other program
 * =================================================================================================
*/
struct rk3399pro__frame_in *rk3399pro__pstruct__frame_in;
struct rk3399pro__frame_out *rk3399pro__pstruct__frame_out;







void rk3399pro_h264_init(void)
{
	rk3399pro__pstruct__frame_in = (struct rk3399pro__frame_in *)malloc(sizeof(rk3399pro__frame_in));
        memset((void *)rk3399pro__pstruct__frame_in, 0, sizeof(rk3399pro__frame_in));
	rk3399pro__pstruct__frame_out = (struct rk3399pro__frame_out *)malloc(sizeof(rk3399pro__frame_out));
	memset((void *)rk3399pro__pstruct__frame_out, 0, sizeof(rk3399pro__frame_out));

	rk3399pro__pstruct__frame_in->rk3399pro__pchar__frame_in = (unsigned char *)v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].start;
	rk3399pro__pstruct__frame_in->rk3399pro__ulong__frame_size_in = (unsigned char *)v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].length;
	


/*
 * =================================================================================================
 * setup param of rk3399pro__struct__enc_cmd
 * =================================================================================================
*/
	rk3399pro__mpi_encode_cmd rk3399pro__struct__enc_cmd;
	rk3399pro__mpi_encode_cmd *rk3399pro__pstruct__enc_cmd = &rk3399pro__struct__enc_cmd;
	memset((void *)rk3399pro__pstruct__enc_cmd, 0, sizeof(rk3399pro__mpi_encode_cmd));
//	memset((void *)rk3399pro__pstruct__enc_data, 0, sizeof(rk3399pro__mpi_encode_data));

	rk3399pro__pstruct__enc_cmd->type = MPP_VIDEO_CodingAVC;
//	MPP_VIDEO_CodingUnused,             /**< Value when coding is N/A */
//	MPP_VIDEO_CodingAutoDetect,         /**< Autodetection of coding type */
//	MPP_VIDEO_CodingMPEG2,              /**< AKA: H.262 */
//	MPP_VIDEO_CodingH263,               /**< H.263 */
//	MPP_VIDEO_CodingMPEG4,              /**< MPEG-4 */
//	MPP_VIDEO_CodingWMV,                /**< Windows Media Video (WMV1,WMV2,WMV3)*/
//	MPP_VIDEO_CodingRV,                 /**< all versions of Real Video */
//	MPP_VIDEO_CodingAVC,                /**< H.264/AVC */
//	MPP_VIDEO_CodingMJPEG,              /**< Motion JPEG */
//	MPP_VIDEO_CodingVP8,                /**< VP8 */
//	MPP_VIDEO_CodingVP9,                /**< VP9 */
//	MPP_VIDEO_CodingVC1 = 0x01000000,   /**< Windows Media Video (WMV1,WMV2,WMV3)*/
//	MPP_VIDEO_CodingFLV1,               /**< Sorenson H.263 */
//	MPP_VIDEO_CodingDIVX3,              /**< DIVX3 */
//	MPP_VIDEO_CodingVP6,
//	MPP_VIDEO_CodingHEVC,               /**< H.265/HEVC */
//	MPP_VIDEO_CodingAVSPLUS,            /**< AVS+ */
//	MPP_VIDEO_CodingAVS,                /**< AVS profile=0x20 */
//	MPP_VIDEO_CodingKhronosExtensions = 0x6F000000, /**< Reserved region for introducing Khronos Standard Extensions */
//	MPP_VIDEO_CodingVendorStartUnused = 0x7F000000, /**< Reserved region for introducing Vendor Extensions */

	rk3399pro__pstruct__enc_cmd->width = RK3399PRO_PICTURE_WIDTH;
	rk3399pro__pstruct__enc_cmd->height = RK3399PRO_PICTURE_HEIGHT;
	rk3399pro__pstruct__enc_cmd->format = MPP_FMT_YUV422_YUYV;
//	rk3399pro__pstruct__enc_cmd->format = MPP_FMT_YUV422P;

//	MPP_FMT_YUV420SP        = MPP_FRAME_FMT_YUV,        /* YYYY... UV... (NV12)     */
//	/*
//	 * A rockchip specific pixel format, without gap between pixel aganist
//	 * the P010_10LE/P010_10BE
//	 */
//	MPP_FMT_YUV420SP_10BIT,
//    	MPP_FMT_YUV422SP,                                   /* YYYY... UVUV... (NV24)   */
//    	MPP_FMT_YUV422SP_10BIT,                             ///< Not part of ABI
//    	MPP_FMT_YUV420P,                                    /* YYYY... U...V...  (I420) */
//    	MPP_FMT_YUV420SP_VU,                                /* YYYY... VUVUVU... (NV21) */
//    	MPP_FMT_YUV422P,                                    /* YYYY... UU...VV...(422P) */
//    	MPP_FMT_YUV422SP_VU,                                /* YYYY... VUVUVU... (NV42) */
//    	MPP_FMT_YUV422_YUYV,                                /* YUYVYUYV... (YUY2)       */
//    	MPP_FMT_YUV422_UYVY,                                /* UYVYUYVY... (UYVY)       */
//    	MPP_FMT_YUV400SP,                                   /* YYYY...                  */
//    	MPP_FMT_YUV440SP,                                   /* YYYY... UVUV...          */
//    	MPP_FMT_YUV411SP,                                   /* YYYY... UV...            */
//    	MPP_FMT_YUV444SP,                                   /* YYYY... UVUVUVUV...      */
//    	MPP_FMT_YUV_BUTT,
//    	MPP_FMT_RGB565          = MPP_FRAME_FMT_RGB,        /* 16-bit RGB               */
//    	MPP_FMT_BGR565,                                     /* 16-bit RGB               */
//    	MPP_FMT_RGB555,                                     /* 15-bit RGB               */
//    	MPP_FMT_BGR555,                                     /* 15-bit RGB               */
//    	MPP_FMT_RGB444,                                     /* 12-bit RGB               */
//    	MPP_FMT_BGR444,                                     /* 12-bit RGB               */
//    	MPP_FMT_RGB888,                                     /* 24-bit RGB               */
//    	MPP_FMT_BGR888,                                     /* 24-bit RGB               */
//    	MPP_FMT_RGB101010,                                  /* 30-bit RGB               */
//    	MPP_FMT_BGR101010,                                  /* 30-bit RGB               */
//    	MPP_FMT_ARGB8888,                                   /* 32-bit RGB               */
//    	MPP_FMT_ABGR8888,                                   /* 32-bit RGB               */
//    	MPP_FMT_RGB_BUTT,
//    	/* simliar to I420, but Pixels are grouped in macroblocks of 8x4 size  */
//    	MPP_FMT_YUV420_8Z4      = MPP_FRAME_FMT_COMPLEX,
//    	/* The end of the formats have a complex layout */
//    	MPP_FMT_COMPLEX_BUTT,
//    	MPP_FMT_BUTT            = MPP_FMT_COMPLEX_BUTT,







	MPP_RET ret = MPP_OK;
	mpp_log("rk3399pro_mpi_encode start! \n");
	
	ret = rk3399pro_ctx_init(&rk3399pro__pstruct__enc_data, rk3399pro__pstruct__enc_cmd);
	if (ret) {
	    mpp_err_f("data init failed ret %d\n", ret);
	    goto RK3399PRO_ENC_OUT;
	}
	
	ret = mpp_buffer_get(NULL, &rk3399pro__pstruct__enc_data->frm_buf, rk3399pro__pstruct__enc_data->frame_size);
	if (ret) {
	    mpp_err_f("failed to get buffer for input frame ret %d\n", ret);
	    goto RK3399PRO_ENC_OUT;
	}
	
	mpp_log("mpi_enc_test encoder test start w %d h %d type %d\n",
	        p->width, p->height, p->type);
	
	// encoder demo
	ret = mpp_create(&rk3399pro__pstruct__enc_data->ctx, &rk3399pro__pstruct__enc_data->mpi);
	if (ret) {
	    mpp_err("mpp_create failed ret %d\n", ret);
	    goto RK3399PRO_ENC_OUT;
	}
	
	ret = mpp_init(rk3399pro__pstruct__enc_data->ctx, MPP_CTX_ENC, rk3399pro__pstruct__enc_data->type);
	if (ret) {
	    mpp_err("mpp_init failed ret %d\n", ret);
	    goto RK3399PRO_ENC_OUT;
	}
	
	ret = rk3399pro__mpp_setup(rk3399pro__pstruct__enc_data);
	if (ret) {
	    mpp_err_f("mpp setup failed ret %d\n", ret);
	    goto RK3399PRO_ENC_OUT;
	}

//	ret = p->mpi->reset(p->ctx);
//	if (ret) {
//	    mpp_err("mpi->reset failed\n");
//	    goto RK3399PRO_ENC_OUT;
//	}


RK3399PRO_ENC_OUT:
	return ret;
}


void rk3399pro__h264_encode(void)
{
	rk3399pro__pstruct__frame_in->rk3399pro__pchar__frame_in = (unsigned char *)v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].start;
	rk3399pro__pstruct__frame_in->rk3399pro__ulong__frame_size_in = (unsigned char *)v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].length;


//	ret = mpp_buffer_get(NULL, &p->frm_buf, p->frame_size);
//	if (ret) {
//	    mpp_err_f("failed to get buffer for input frame ret %d\n", ret);
//	    goto MPP_TEST_OUT;
//	}


	ret = rk3399pro__mpp_run(rk3399pro__pstruct__enc_data);
	if (ret) {
	    mpp_err_f("test mpp run failed ret %d\n", ret);
	    goto MPP_TEST_OUT;
	}



//	ret = p->mpi->reset(p->ctx);
//	if (ret) {
//	    mpp_err("mpi->reset failed\n");
//	    goto MPP_TEST_OUT;

}


void rk3399pro__h264_decode(void)
{

}


void rk3399pro__h264_quit(void)
{
	rk3399pro__mpi_encode_data *p = NULL;
	p = rk3399pro__pstruct__enc_data;
	if(p)
		MPP_FREE(p);
	if(rk3399pro__pstruct__frame_in)
		free(rk3399pro__pstruct__frame_in);
	if(rk3399pro__pstruct__frame_out)
		free(rk3399pro__pstruct__frame_out);
	return;
}






MPP_RET rk3399pro__ctx_init(rk3399pro__mpi_encode_data **data, rk3399pro__mpi_encode_cmd *cmd)
{
	rk3399pro__mpi_encode_data *p = NULL;
	MPP_RET ret = MPP_OK;
	
	if (!data || !cmd) {
	    mpp_err_f("invalid input data %p cmd %p\n", data, cmd);
	    return MPP_ERR_NULL_PTR;
	}
	
	p = mpp_calloc(rk3399pro__mpi_encode_data, 1);
	if (!p) {
	    mpp_err_f("create rk3399pro__mpi_encode_data failed\n");
	    ret = MPP_ERR_MALLOC;
	    goto RET;
	}
	
	// get paramter from cmd
	p->width        = cmd->width;
	p->height       = cmd->height;
	p->hor_stride   = MPP_ALIGN(cmd->width, 16);
	p->ver_stride   = MPP_ALIGN(cmd->height, 16);
	p->fmt          = cmd->format;
	p->type         = cmd->type;
	if (cmd->type == MPP_VIDEO_CodingMJPEG)
	    cmd->num_frames = 1;
	p->num_frames   = cmd->num_frames;
	


	p->rk3399pro__pchar__in_frame = (unsigned char *)v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].start;
	p->rk3399pro__pchar__out_frame = rk3399pro__point__out_frame->rk3399pro__pchar__out_frame;
//	if (cmd->have_input) {
//	    p->fp_input = fopen(cmd->file_input, "rb");
//	    if (NULL == p->fp_input) {
//	        mpp_err("failed to open input file %s\n", cmd->file_input);
//	        mpp_err("create default yuv image for test\n");
//	    }
//	}
//	
//	if (cmd->have_output) {
//	    p->fp_output = fopen(cmd->file_output, "w+b");
//	    if (NULL == p->fp_output) {
//	        mpp_err("failed to open output file %s\n", cmd->file_output);
//	        ret = MPP_ERR_OPEN_FILE;
//	    }
//	}
	
	// update resource parameter
	if (p->fmt <= MPP_FMT_YUV420SP_VU)
	    p->frame_size = p->hor_stride * p->ver_stride * 3 / 2;
	else if (p->fmt <= MPP_FMT_YUV422_UYVY) {
	    // NOTE: yuyv and uyvy need to double stride
	    p->hor_stride *= 2;
	    p->frame_size = p->hor_stride * p->ver_stride;
	} else
	    p->frame_size = p->hor_stride * p->ver_stride * 4;
	p->packet_size  = p->width * p->height;

RET:
	*data = p;
	return ret;
}


MPP_RET rk3399pro__mpp_setup(rk3399pro__mpi_encode_data *p)
{
	MPP_RET ret;
	MppApi *mpi;
	MppCtx ctx;
	
	MppEncCodecCfg *codec_cfg;
	MppEncPrepCfg *prep_cfg;
	MppEncRcCfg *rc_cfg;
	
	if (NULL == p)
	    return MPP_ERR_NULL_PTR;
	
	mpi = p->mpi;
	ctx = p->ctx;

	codec_cfg = &p->codec_cfg;
	prep_cfg = &p->prep_cfg;
	rc_cfg = &p->rc_cfg;
	
	/* setup default parameter */
	p->fps = 30;
	p->gop = 60;
	p->bps = p->width * p->height / 8 * p->fps;
	
	prep_cfg->change        = MPP_ENC_PREP_CFG_CHANGE_INPUT |
	                          MPP_ENC_PREP_CFG_CHANGE_ROTATION |
	                          MPP_ENC_PREP_CFG_CHANGE_FORMAT;
	prep_cfg->width         = p->width;
	prep_cfg->height        = p->height;
	prep_cfg->hor_stride    = p->hor_stride;
	prep_cfg->ver_stride    = p->ver_stride;
	prep_cfg->format        = p->fmt;
	prep_cfg->rotation      = MPP_ENC_ROT_0;
	ret = mpi->control(ctx, MPP_ENC_SET_PREP_CFG, prep_cfg);
	if (ret) {
	    mpp_err("mpi control enc set prep cfg failed ret %d\n", ret);
	    goto RET;
	}
	
	rc_cfg->change  = MPP_ENC_RC_CFG_CHANGE_ALL;
	rc_cfg->rc_mode = MPP_ENC_RC_MODE_CBR;
	rc_cfg->quality = MPP_ENC_RC_QUALITY_MEDIUM;
	
	if (rc_cfg->rc_mode == MPP_ENC_RC_MODE_CBR) {
	    /* constant bitrate has very small bps range of 1/16 bps */
	    rc_cfg->bps_target   = p->bps;
	    rc_cfg->bps_max      = p->bps * 17 / 16;
	    rc_cfg->bps_min      = p->bps * 15 / 16;
	} else if (rc_cfg->rc_mode ==  MPP_ENC_RC_MODE_VBR) {
	    if (rc_cfg->quality == MPP_ENC_RC_QUALITY_CQP) {
	        /* constant QP does not have bps */
	        rc_cfg->bps_target   = -1;
	        rc_cfg->bps_max      = -1;
	        rc_cfg->bps_min      = -1;
	    } else {
	        /* variable bitrate has large bps range */
	        rc_cfg->bps_target   = p->bps;
	        rc_cfg->bps_max      = p->bps * 17 / 16;
	        rc_cfg->bps_min      = p->bps * 1 / 16;
	    }
	}
	
	/* fix input / output frame rate */
	rc_cfg->fps_in_flex      = 0;
	rc_cfg->fps_in_num       = p->fps;
	rc_cfg->fps_in_denorm    = 1;
	rc_cfg->fps_out_flex     = 0;
	rc_cfg->fps_out_num      = p->fps;
	rc_cfg->fps_out_denorm   = 1;
	
	rc_cfg->gop              = p->gop;
	rc_cfg->skip_cnt         = 0;
	
	mpp_log("mpi_enc_test bps %d fps %d gop %d\n",
	        rc_cfg->bps_target, rc_cfg->fps_out_num, rc_cfg->gop);
	ret = mpi->control(ctx, MPP_ENC_SET_RC_CFG, rc_cfg);
	if (ret) {
	    mpp_err("mpi control enc set rc cfg failed ret %d\n", ret);
	    goto RET;
	}
	
	codec_cfg->coding = p->type;
	switch (codec_cfg->coding) {
	case MPP_VIDEO_CodingAVC : {
	    codec_cfg->h264.change = MPP_ENC_H264_CFG_CHANGE_PROFILE |
	                             MPP_ENC_H264_CFG_CHANGE_ENTROPY |
	                             MPP_ENC_H264_CFG_CHANGE_TRANS_8x8;
	    /*
	     * H.264 profile_idc parameter
	     * 66  - Baseline profile
	     * 77  - Main profile
	     * 100 - High profile
	     */
	    codec_cfg->h264.profile  = 100;
	    /*
	     * H.264 level_idc parameter
	     * 10 / 11 / 12 / 13    - qcif@15fps / cif@7.5fps / cif@15fps / cif@30fps
	     * 20 / 21 / 22         - cif@30fps / half-D1@@25fps / D1@12.5fps
	     * 30 / 31 / 32         - D1@25fps / 720p@30fps / 720p@60fps
	     * 40 / 41 / 42         - 1080p@30fps / 1080p@30fps / 1080p@60fps
	     * 50 / 51 / 52         - 4K@30fps
	     */
	    codec_cfg->h264.level    = 40;
	    codec_cfg->h264.entropy_coding_mode  = 1;
	    codec_cfg->h264.cabac_init_idc  = 0;
	    codec_cfg->h264.transform8x8_mode = 1;
	} break;
	case MPP_VIDEO_CodingMJPEG : {
	    codec_cfg->jpeg.change  = MPP_ENC_JPEG_CFG_CHANGE_QP;
	    codec_cfg->jpeg.quant   = 10;
	} break;
	case MPP_VIDEO_CodingVP8 : {
	} break;
	case MPP_VIDEO_CodingHEVC : {
	    codec_cfg->h265.change = MPP_ENC_H265_CFG_INTRA_QP_CHANGE;
	    codec_cfg->h265.intra_qp = 26;
	} break;
	default : {
	    mpp_err_f("support encoder coding type %d\n", codec_cfg->coding);
	} break;
	}
	ret = mpi->control(ctx, MPP_ENC_SET_CODEC_CFG, codec_cfg);
	if (ret) {
	    mpp_err("mpi control enc set codec cfg failed ret %d\n", ret);
	    goto RET;
	}
	
	/* optional */
	p->sei_mode = MPP_ENC_SEI_MODE_ONE_FRAME;
	ret = mpi->control(ctx, MPP_ENC_SET_SEI_CFG, &p->sei_mode);
	if (ret) {
	    mpp_err("mpi control enc set sei cfg failed ret %d\n", ret);
	    goto RET;
	}

RET:
	return ret;
}



MPP_RET test_mpp_run(rk3399pro__mpi_encode_data *p)
{
	MPP_RET ret;
	MppApi *mpi;
	MppCtx ctx;
	
	if (NULL == p)
	    return MPP_ERR_NULL_PTR;
	
	mpi = p->mpi;
	ctx = p->ctx;
	
	if (p->type == MPP_VIDEO_CodingAVC) {
	    MppPacket packet = NULL;
	    ret = mpi->control(ctx, MPP_ENC_GET_EXTRA_INFO, &packet);
	    if (ret) {
	        mpp_err("mpi control enc get extra info failed\n");
	        goto RET;
	    }
	
	    /* get and write sps/pps for H.264 */
	    if (packet) {
	        void *ptr   = mpp_packet_get_pos(packet);
	        size_t len  = mpp_packet_get_length(packet);
	
	        if (p->fp_output)
	            fwrite(ptr, 1, len, p->fp_output);
	
	        packet = NULL;
	    }
	}
	
	while (!p->pkt_eos) {
	    MppFrame frame = NULL;
	    MppPacket packet = NULL;
	    void *buf = mpp_buffer_get_ptr(p->frm_buf);
	
	    if (p->fp_input) {
	        ret = read_yuv_image(buf, p->fp_input, p->width, p->height,
	                             p->hor_stride, p->ver_stride, p->fmt);
	        if (ret == MPP_NOK || feof(p->fp_input)) {
	            mpp_log("found last frame. feof %d\n", feof(p->fp_input));
	            p->frm_eos = 1;
	        } else if (ret == MPP_ERR_VALUE)
	            goto RET;
	    } else {
	        ret = fill_yuv_image(buf, p->width, p->height, p->hor_stride,
	                             p->ver_stride, p->fmt, p->frame_count);
	        if (ret)
	            goto RET;
	    }
	
	    ret = mpp_frame_init(&frame);
	    if (ret) {
	        mpp_err_f("mpp_frame_init failed\n");
	        goto RET;
	    }
	
	    mpp_frame_set_width(frame, p->width);
	    mpp_frame_set_height(frame, p->height);
	    mpp_frame_set_hor_stride(frame, p->hor_stride);
	    mpp_frame_set_ver_stride(frame, p->ver_stride);
	    mpp_frame_set_fmt(frame, p->fmt);
	    mpp_frame_set_eos(frame, p->frm_eos);
	
	    if (p->fp_input && feof(p->fp_input))
	        mpp_frame_set_buffer(frame, NULL);
	    else
	        mpp_frame_set_buffer(frame, p->frm_buf);
	
	    ret = mpi->encode_put_frame(ctx, frame);
	    if (ret) {
	        mpp_err("mpp encode put frame failed\n");
	        goto RET;
	    }
	
	    ret = mpi->encode_get_packet(ctx, &packet);
	    if (ret) {
	        mpp_err("mpp encode get packet failed\n");
	        goto RET;
	    }
	
	    if (packet) {
	        // write packet to file here
	        void *ptr   = mpp_packet_get_pos(packet);
	        size_t len  = mpp_packet_get_length(packet);
	
	        p->pkt_eos = mpp_packet_get_eos(packet);
	
	        if (p->fp_output)
	            fwrite(ptr, 1, len, p->fp_output);
	        mpp_packet_deinit(&packet);
	
	        mpp_log_f("encoded frame %d size %d\n", p->frame_count, len);
	        p->stream_size += len;
	        p->frame_count++;
	
	        if (p->pkt_eos) {
	            mpp_log("found last packet\n");
	            mpp_assert(p->frm_eos);
	        }
	    }
	    if (p->num_frames && p->frame_count >= p->num_frames) {
	        mpp_log_f("encode max %d frames", p->frame_count);
	        break;
	    }
	    if (p->frm_eos && p->pkt_eos)
	        break;
	}
RET:
	return ret;
}







