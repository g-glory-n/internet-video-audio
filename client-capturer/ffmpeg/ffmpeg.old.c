/*
 * =================================================================================================
 * ffmpeg.old.c
 * =================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>

#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>

#include "ffmpeg.old.h"
#include "../v4l2/v4l2.h"
#include "../x264/x264.h"
#include "../x265/x265.h"





/*
 * =================================================================================================
 * the data structure of ffmpeg_old encoding picture necessarily
 * =================================================================================================
*/
//AVFormatContext *AVFormatContext_encode__point__format_context = NULL;
//AVOutputFormat *AVOutputFormat_encode__point__output_format = NULL;
//AVStream *AVStream_encode__point__stream = NULL;
AVCodec *AVCodec_encode__point__codec = NULL;
AVCodecContext *AVCodecContext_encode__point__codec_context = NULL;
AVFrame *AVFrame_encode__point__frame = NULL;
AVPacket *AVPacket_encode__point__packet = NULL;
//enum AVCodecID AVCodecID_encode__codec_id = AV_CODEC_ID_H264;//AV_CODEC_ID_HEVC
enum AVCodecID AVCodecID_encode__codec_id = AV_CODEC_ID_HEVC;//AV_CODEC_ID_H264

unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others = NULL;

/*
 * =================================================================================================
 * the data structure of ffmpeg_old decoding picture necessarily
 * =================================================================================================
*/
AVCodec *AVCodec_decode__point__codec = NULL;
AVCodecContext *AVCodecContext_decode__point__codec_context = NULL;
AVFrame *AVFrame_decode__point__frame = NULL;
AVPacket *AVPacket_decode__point__packet = NULL;
AVCodecParserContext *AVCodecParserContext_decode__point__codec_parser_context = NULL;
enum AVCodecID AVCodecID_decode__codec_id = AV_CODEC_ID_H264;//AV_CODEC_ID_HEVC
//enum AVCodecID AVCodecID_decode__codec_id = AV_CODEC_ID_HEVC;//AV_CODEC_ID_H264


/*
 * =================================================================================================
 * the necessary data point of separating YUYV
 * =================================================================================================
*/
unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_Y = NULL;
unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_U = NULL;
unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_V = NULL;



/*
 * =================================================================================================
 * can be called for other program 
 * =================================================================================================
*/
signed int ffmpeg_old_programmer_define_signed_int__size_after_ffmpeg_old = 0;
unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_encode = NULL;

unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode = NULL;

void ffmpeg_old_init(void)
{
	ffmpeg_old_encode_init();
	ffmpeg_old_decode_init();
}

void ffmpeg_old_encode_init(void)
{
/*
 * =================================================================================================
 * the data structure of ffmpeg_old encoding picture necessarily
 * =================================================================================================
*/
//	AVCodec *AVCodec_encode__point__codec = NULL;
//	AVCodecContext *AVCodecContext_encode__point__codec_context = NULL;
//	AVFrame *AVFrame_encode__point__frame = NULL;
//	AVPacket *AVPacket_encode__point__packet = NULL;
//	enum AVCodecID AVCodecID_encode__codec_id = AV_CODEC_ID_HEVC;//AV_CODEC_ID_H264
//	unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others = NULL;


	ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others = (unsigned char *)malloc(FFMPEG_PICTURE_WIDTH*FFMPEG_PICTURE_HEIGHT*2);
/*
 * =================================================================================================
 * the part of ffmpeg_old encode
 * =================================================================================================
*/

/*	
	av_register_all();
	AVFormatContext__point__format_context = avformat_alloc_context();
	AVOutputFormat__point__output_format = av_guess_format(NULL, "ds.h264", NULL);
	AVFormatContext__point__format_context->oformat = AVOutputFormat__point__output_format;

	avio_open(&AVFormatContext__point__format_context, "ds.264", AVIO_FLAG_READ_WRITE);
	AVStream__point__stream = avformat_new_stream(AVFormatContext__point__format_context, 0);
*/

//	#include <libavcodec/avcodec.h>
//	void avcodec_register_all(void);
	avcodec_register_all();

//	#include <libavcodec/avcodec.h>
//	AVCodec *avcodec_find_encoder_by_name(const char *name);
//	AVCodec_encode__point__codec = avcodec_find_encoder_by_name("xxx");

//	#include <libavcodec/avcodec.h>
//	AVCodec *avcodec_find_encoder(enum AVCodecID id);
	AVCodec_encode__point__codec = avcodec_find_encoder(AVCodecID_encode__codec_id);
	if(NULL == AVCodec_encode__point__codec)
	{
		fprintf(stderr, "\nfind encoder failed ! -> avcodec_find_encoder();\n");
		exit(FAILURE);
	}

//	#include <libavcodec/avcodec.h>
//	AVCodecContext *avcodec_alloc_context3(const AVCodec *codec);
	AVCodecContext_encode__point__codec_context = avcodec_alloc_context3(AVCodec_encode__point__codec);
	if(NULL == AVCodecContext_encode__point__codec_context)
	{
		fprintf(stderr, "\nalloc context failed ! -> avcodec_alloc_context3();\n");
		exit(FAILURE);
	}
	AVCodecContext_encode__point__codec_context->bit_rate = 2000000;
	AVCodecContext_encode__point__codec_context->width = FFMPEG_PICTURE_WIDTH;
	AVCodecContext_encode__point__codec_context->height = FFMPEG_PICTURE_HEIGHT;
	AVCodecContext_encode__point__codec_context->time_base.num = 1;
	AVCodecContext_encode__point__codec_context->time_base.den = 30;
	AVCodecContext_encode__point__codec_context->gop_size = 10;
	AVCodecContext_encode__point__codec_context->max_b_frames = 1;
//	#include <libavutil/pixfmt.h>
//	enum AVPixelFormat
//	{
//	...
//	AV_PIX_FMT_YUV420P,   ///< planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples)
//	AV_PIX_FMT_YUYV422,   ///< packed YUV 4:2:2, 16bpp, Y0 Cb Y1 Cr
//	AV_PIX_FMT_RGB24,     ///< packed RGB 8:8:8, 24bpp, RGBRGB...
//	AV_PIX_FMT_BGR24,     ///< packed RGB 8:8:8, 24bpp, BGRBGR...
//	AV_PIX_FMT_YUV422P,   ///< planar YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples)
//	AV_PIX_FMT_YUV444P,   ///< planar YUV 4:4:4, 24bpp, (1 Cr & Cb sample per 1x1 Y samples)
//	...
//	};
	AVCodecContext_encode__point__codec_context->pix_fmt = AV_PIX_FMT_YUV422P;

//	#include <libavutil/opt.h>
//	int av_opt_set(void *obj, const char *name, const char *val, int search_flags);
//	if(AVCodecID_encode__codec_id == AV_CODEC_ID_H264)
//		av_opt_set(AVCodecContext_encode__point__codec_context->priv_data, "preset", "slow", 0);

//	#include <libavcodec/avcodec.h>
//	int avcodec_open2(AVCodecContext *avctx, const AVCodec *codec, AVDictionary **options);
//	@return zero on success, a negative value on error
	if(avcodec_open2(AVCodecContext_encode__point__codec_context, AVCodec_encode__point__codec, NULL) < 0)
	{
		fprintf(stderr, "\nopen codec failed ! -> avcodec_open2();\n");
		exit(FAILURE);
	}

//	#include <libavutil/frame.h>
//	AVFrame *av_frame_alloc(void);
	AVFrame_encode__point__frame = av_frame_alloc();
	if(NULL == AVFrame_encode__point__frame)
	{
		fprintf(stderr, "\nalloc frame failed ! -> av_frame_alloc();\n");
		exit(FAILURE);
	}
	AVFrame_encode__point__frame->format = AVCodecContext_encode__point__codec_context->pix_fmt;
	AVFrame_encode__point__frame->width = AVCodecContext_encode__point__codec_context->width;
	AVFrame_encode__point__frame->height = AVCodecContext_encode__point__codec_context->height;

//	#include <libavutil/imgutils.h>
//	int av_image_alloc(uint8_t *pointers[4], int linesizes[4],int w, int h, enum AVPixelFormat pix_fmt, int align);
	if(-1 == av_image_alloc(AVFrame_encode__point__frame->data, AVFrame_encode__point__frame->linesize, AVCodecContext_encode__point__codec_context->width, AVCodecContext_encode__point__codec_context->height, AVCodecContext_encode__point__codec_context->pix_fmt, 1))
	{
		fprintf(stderr, "\nalloc iamge failed ! -> av_image_alloc();\n");
		exit(FAILURE);
	}

//	#include <libavcodec/avcodec.h>
//	AVPacket *av_packet_alloc(void);
	if(NULL == (AVPacket_encode__point__packet = av_packet_alloc()))
	{
		fprintf(stderr, "\nalloc packet failed ! -> av_packet_alloc();\n");
		exit(FAILURE);
	}
	av_init_packet(AVPacket_encode__point__packet);

	ffmpeg_old_programmer_define_unsigned_char_point__picture_Y = AVFrame_encode__point__frame->data[0];
	ffmpeg_old_programmer_define_unsigned_char_point__picture_U = AVFrame_encode__point__frame->data[1];
	ffmpeg_old_programmer_define_unsigned_char_point__picture_V = AVFrame_encode__point__frame->data[2];


/*
 * =================================================================================================
 * the part of ffmpeg_old decode
 * =================================================================================================
*/
}


void ffmpeg_old_decode_init(void)
{
/*
 * =================================================================================================
 * the data structure of ffmpeg_old decoding picture necessarily
 * =================================================================================================
*/
//	AVCodec *AVCodec_decode__point__codec = NULL;
//	AVCodecContext *AVCodecContext_decode__point__codec_context = NULL;
//	AVFrame *AVFrame_decode__point__frame = NULL;
//	AVPacket *AVPacket_decode__point__packet = NULL;
//	AVCodecParserContext *AVCodecParserContext_decode__point__codec_parser_context = NULL;
//	enum AVCodecID AVCodecID_decode__codec_id = AV_CODEC_ID_HEVC;//AV_CODEC_ID_H264

//	extern AVCodec ff_h264_decoder;
//	extern AVCodevParser ff_h264_parser;
//	avcodec_register(&ff_h264_decoder);
//	av_register_codec_parser(&ff_h264_parser);
	
	ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode = (unsigned char *)malloc(FFMPEG_PICTURE_WIDTH*FFMPEG_PICTURE_HEIGHT*2);
	
	avcodec_register_all();
	
	AVCodec_decode__point__codec = avcodec_find_decoder(AVCodecID_decode__codec_id);
	if(NULL == AVCodec_decode__point__codec)
	{
		fprintf(stderr, "\nfind decoder failed ! -> avcodec_find_decoder();\n");
		exit(FAILURE);
	}

	AVCodecContext_decode__point__codec_context = avcodec_alloc_context3(AVCodec_decode__point__codec);
	if(NULL == AVCodecContext_decode__point__codec_context)
	{
		fprintf(stderr, "\nalloc context failed ! -> avcodec_alloc_context3();\n");
		exit(FAILURE);
	}

	AVCodecParserContext_decode__point__codec_parser_context = av_parser_init(AVCodecID_decode__codec_id);
	if(NULL == AVCodecParserContext_decode__point__codec_parser_context)
	{
		fprintf(stderr, "\ninit parser failed ! -> av_parser_init();\n");
		exit(FAILURE);
	}

	if(avcodec_open2(AVCodecContext_decode__point__codec_context, AVCodec_decode__point__codec, NULL) < 0)
	{
		fprintf(stderr, "\nopen decoder failed ! -> avcodec_open2();\n");
		exit(FAILURE);
	}

	AVFrame_decode__point__frame = av_frame_alloc();
	if(NULL == AVFrame_decode__point__frame)
	{
		fprintf(stderr, "\nalloc frame failed ! -> av_frame_alloc();\n");
		exit(FAILURE);
	}

	AVPacket_decode__point__packet = av_packet_alloc();
	if(NULL == AVPacket_decode__point__packet)
	{
		fprintf(stderr, "\nalloc packet failed ! -> av_packet_alloc();\n");
		exit(FAILURE);
	}
	av_init_packet(AVPacket_decode__point__packet);

}


void ffmpeg_old_picture_encode(void)
{
/*
 * =================================================================================================
 * the data structure of ffmpeg_old encoding picture necessarily
 * =================================================================================================
*/
//	AVCodec *AVCodec_encode__point__codec = NULL;
//	AVCodecContext *AVCodecContext_encode__point__codec_context = NULL;
//	AVFrame *AVFrame_encode__point__frame = NULL;
//	AVPacket *AVPacket_encode__point__packet = NULL;
//	enum AVCodecID AVCodecID_encode__codec_id = AV_CODEC_ID_HEVC;//AV_CODEC_ID_H264

/*
 * =================================================================================================
 * init AVPacket_encode__point__packet
 * =================================================================================================
*/
//	av_init_packet(AVPacket_encode__point__packet);
	AVPacket_encode__point__packet->data = NULL;
	AVPacket_encode__point__packet->size = 0;

	unsigned long ffmpeg_old_programmer_define_unsigned_long__for_i0 = 0;
	unsigned long ffmpeg_old_programmer_define_unsigned_long__picture_size = FFMPEG_PICTURE_WIDTH*FFMPEG_PICTURE_HEIGHT*2;
	unsigned long ffmpeg_old_programmer_define_unsigned_long__index_Y = 0;
	unsigned long ffmpeg_old_programmer_define_unsigned_long__index_U = 0;
	unsigned long ffmpeg_old_programmer_define_unsigned_long__index_V = 0;

/*
 * =================================================================================================
 * separate "Y U V" data of YUYV to AVFrame_encode__point__frame->data[0, 1, 2];
 * =================================================================================================
*/
	memcpy(ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others, (unsigned char *)v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].start, V4L2_PICTURE_WIDTH*V4L2_PICTURE_HEIGHT*2);
	for(ffmpeg_old_programmer_define_unsigned_long__for_i0 = 0;ffmpeg_old_programmer_define_unsigned_long__for_i0 < ffmpeg_old_programmer_define_unsigned_long__picture_size; ffmpeg_old_programmer_define_unsigned_long__for_i0 = ffmpeg_old_programmer_define_unsigned_long__for_i0 + 4)
	{
		ffmpeg_old_programmer_define_unsigned_char_point__picture_Y[ffmpeg_old_programmer_define_unsigned_long__index_Y++] = ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others[ffmpeg_old_programmer_define_unsigned_long__for_i0 + 0];
		ffmpeg_old_programmer_define_unsigned_char_point__picture_U[ffmpeg_old_programmer_define_unsigned_long__index_U++] = ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others[ffmpeg_old_programmer_define_unsigned_long__for_i0 + 1];
		ffmpeg_old_programmer_define_unsigned_char_point__picture_Y[ffmpeg_old_programmer_define_unsigned_long__index_Y++] = ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others[ffmpeg_old_programmer_define_unsigned_long__for_i0 + 2];
		ffmpeg_old_programmer_define_unsigned_char_point__picture_V[ffmpeg_old_programmer_define_unsigned_long__index_V++] = ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others[ffmpeg_old_programmer_define_unsigned_long__for_i0 + 3];
	}





	static int ffmpeg_old_programmer_define_int__got_output = 0;
	static unsigned long ffmpeg_old_programmer_define_unsigned_int__pts = 0;
	AVFrame_encode__point__frame->pts = ffmpeg_old_programmer_define_unsigned_int__pts++;
//	#include <libavcodec/avcodec.h>
//	int avcodec_encode_video2(AVCodecContext *avctx, AVPacket *avpkt, const AVFrame *frame, int *got_packet_ptr);
	if(avcodec_encode_video2(AVCodecContext_encode__point__codec_context, AVPacket_encode__point__packet, AVFrame_encode__point__frame, &ffmpeg_old_programmer_define_int__got_output) < 0)
	{
		fprintf(stderr, "\nencode video failed ! -> avcodec_encode_video2();\n");
		exit(FAILURE);
	}




/*
 * =================================================================================================
 * write to memory
 * =================================================================================================
*/
	ffmpeg_old_programmer_define_signed_int__size_after_ffmpeg_old = 0;
//	if(ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_encode)
//	{
//		free(ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_encode);
//	}
//	ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_encode = (unsigned char *)malloc(AVPacket_encode__point__packet->size);
//	memcpy(ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_encode, AVPacket_encode__point__packet->data, AVPacket_encode__point__packet->size);
	ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_encode = AVPacket_encode__point__packet -> data;
	ffmpeg_old_programmer_define_signed_int__size_after_ffmpeg_old = AVPacket_encode__point__packet->size;


        printf("picture size after ffmpeg_old encode: %d Byte\n", ffmpeg_old_programmer_define_signed_int__size_after_ffmpeg_old);

}

void ffmpeg_old_picture_decode(void)
{
/*
 * =================================================================================================
 * the data structure of ffmpeg_old decoding picture necessarily
 * =================================================================================================
*/
//      AVCodec *AVCodec_decode__point__codec = NULL;
//      AVCodecContext *AVCodecContext_decode__point__codec_context = NULL;
//      AVFrame *AVFrame_decode__point__frame = NULL;
//      AVPacket *AVPacket_decode__point__packet = NULL;
//      AVCodecParserContext *AVCodecParserContext_decode__point__codec_parser_context = NULL;
//      enum AVCodecID AVCodecID_decode__codec_id = AV_CODEC_ID_HEVC;//AV_CODEC_ID_H264
	static unsigned char ffmpeg_old_programmer_define_unsigned_char__first_time = 0;
	unsigned char *ffmpeg_old_programmer_define_unsigned_char_point__data = NULL;
	signed int ffmpeg_old_programmer_define_signed_int__size = 0;
	signed int ffmpeg_old_programmer_define_signed_int__got_picture = 0;


//	int av_parser_parse2
//		(
//		 	AVCodecParserContext *s,
//			AVCodecContext *avctx,
//			uint8_t **poutbuf, int *poutbuf_size,
//			const uint8_t *buf, int buf_size,
//			int64_t pts, int64_t dts,
//			int64_t pos
//		);

//	int ffmpeg_old_programmer_define_signed_int__length = av_parser_parse2
//		(
//		 	AVCodecParserContext_decode__point__codec_parser_context,
//			AVCodecContext_decode__point__codec_context,
//			AVPacket_decode__point__packet->data,
//			AVPacket_decode__point__packet->size,
//			ffmpeg_old_programmer_define_unsigned_char_point__data,
//			ffmpeg_old_programmer_define_signed_int__size,
//			AV_NOPTS_VALUE, /*0*/
//			AV_NOPTS_VALUE, /*0*/
//			AV_NOPTS_VALUE
//		);
	

/*
 * =================================================================================================
 * fill packet
 * =================================================================================================
*/
//	AVPacket_decode__point__packet -> data = ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_copy_from_others;
//	AVPacket_decode__point__packet -> size = ffmpeg_old_programmer_define_signed_int__size_after_ffmpeg_old;

	AVPacket_decode__point__packet -> data = x264_programmer_define_unsigned_char_point__picture_buffer;
	AVPacket_decode__point__packet -> size = (signed int)x264_programmer_define_unsigned_long__after_x264_size;
	
//	AVPacket_decode__point__packet -> data = x265_programmer_define_unsigned_char_point__picture_buffer;
//	AVPacket_decode__point__packet -> size = (signed int)x265_programmer_define_unsigned_long__after_x265_size;

/*
 * =================================================================================================
 * decode a picture
 * =================================================================================================
*/
//	int avcodec_decode_video2(AVCodecContext *avctx, AVFrame *picture, int *got_picture_ptr, const AVPacket *avpkt);
	if(avcodec_decode_video2(AVCodecContext_decode__point__codec_context, AVFrame_decode__point__frame, &ffmpeg_old_programmer_define_signed_int__got_picture, AVPacket_decode__point__packet) < 0 && AVPacket_decode__point__packet -> size != 0)
	{
		fprintf(stderr, "\ndecode video failed ! -> avcodec_decode_video2();\n");
		exit(FAILURE);
	}

/*
 * =================================================================================================
 * do something after decode a picture successfully
 * =================================================================================================
*/
	if(ffmpeg_old_programmer_define_signed_int__got_picture)
	{
		if(!ffmpeg_old_programmer_define_unsigned_char__first_time)
		{
			fprintf(stdout, "\n%s start to decode video !\n", AVCodecContext_decode__point__codec_context -> codec -> long_name);
			fprintf(stdout, "video information: \nwidth: %d\theight: %d\n\n", AVCodecContext_decode__point__codec_context -> width, AVCodecContext_decode__point__codec_context -> height);
			ffmpeg_old_programmer_define_unsigned_char__first_time = 1;
		}
		fprintf(stdout, "decode a frame successfully !\n");
	
		switch(AVCodecContext_decode__point__codec_context -> pix_fmt)
		{
			case (AV_PIX_FMT_YUV444P):
			{
				
			}break;
			case (AV_PIX_FMT_YUV422P):
			{
				signed int ffmpeg_old_index = 0;
				signed int ffmpeg_old_y_i = 0;
				signed int ffmpeg_old_u_i = 0;
				signed int ffmpeg_old_v_i = 0;
				for(ffmpeg_old_index = 0 ; ffmpeg_old_index < (AVFrame_decode__point__frame -> width)*(AVFrame_decode__point__frame -> height)*2; )
				{
					ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode[ffmpeg_old_index++] = AVFrame_decode__point__frame -> data[0][ffmpeg_old_y_i++];
					ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode[ffmpeg_old_index++] = AVFrame_decode__point__frame -> data[1][ffmpeg_old_u_i++];
					ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode[ffmpeg_old_index++] = AVFrame_decode__point__frame -> data[0][ffmpeg_old_y_i++];
					ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode[ffmpeg_old_index++] = AVFrame_decode__point__frame -> data[2][ffmpeg_old_v_i++];
				}
			}break;
			case (AV_PIX_FMT_YUV420P):
			{
				
			}break;
			default:
			{
				fprintf(stderr, "\nAVCodecContext_decode__point__codec_context -> pix_fmt is out of range !\n");
				exit(FAILURE);
			}
		}

	}
}


void ffmpeg_old_quit(void)
{
	ffmpeg_old_encode_quit();
	ffmpeg_old_decode_quit();
}


void ffmpeg_old_encode_quit(void)
{

/*
 * =================================================================================================
 * ffmpeg_old encoder quit
 * =================================================================================================
*/
/*
 * =================================================================================================
 * the data structure of ffmpeg_old encoding picture necessarily
 * =================================================================================================
*/
//	AVCodec *AVCodec_encode__point__codec = NULL;
//	AVCodecContext *AVCodecContext_encode__point__codec_context = NULL;
//	AVFrame *AVFrame_encode__point__frame = NULL;
//	AVPacket *AVPacket_encode__point__packet = NULL;
//	enum AVCodecID AVCodecID_encode__codec_id = AV_CODEC_ID_HEVC;//AV_CODEC_ID_H264

	avcodec_free_context(&AVCodecContext_encode__point__codec_context);
	av_frame_free(&AVFrame_encode__point__frame);
	av_packet_free(&AVPacket_encode__point__packet);
}


void ffmpeg_old_decode_quit(void)
{
/*
 * =================================================================================================
 * ffmpeg_old decoder quit
 * =================================================================================================
*/
/*
 * =================================================================================================
 * the data structure of ffmpeg_old decoding picture necessarily
 * =================================================================================================
*/
//	AVCodec *AVCodec_decode__point__codec = NULL;
//	AVCodecContext *AVCodecContext_decode__point__codec_context = NULL;
//	AVFrame *AVFrame_decode__point__frame = NULL;
//	AVPacket *AVPacket_decode__point__packet = NULL;
//	AVCodecParserContext *AVCodecParserContext_decode__point__codec_parser_context = NULL;
//	enum AVCodecID AVCodecID_decode__codec_id = AV_CODEC_ID_HEVC;//AV_CODEC_ID_H264

	avcodec_free_context(&AVCodecContext_decode__point__codec_context);
	av_frame_free(&AVFrame_decode__point__frame);
	av_packet_free(&AVPacket_decode__point__packet);

}

