#ifndef _H264_ENCODER_H
#define _H264_ENCODER_H
#include <video/vencoder.h>
#include <video/memoryAdapter.h>
#define ALIGN_4K(x) (((x) + (4095)) & ~(4095))
#define ALIGN_1K(x) (((x) + (1023)) & ~(1023))
#define ALIGN_32B(x) (((x) + (31)) & ~(31))
#define ALIGN_16B(x) (((x) + (15)) & ~(15))
#define ALIGN_8B(x) (((x) + (7)) & ~(7))
struct inputbuf_addr
{
		char* addrVirY;
		char* addrVirC;
};
struct H264_encoder
{
	VideoEncoder* VideoEnc;//编码器
	VencBaseConfig baseConfig;//编码器基本配置
	VencInputBuffer inputBuffer;//编码输入缓冲
	VencOutputBuffer outputBuffer;//编码输出缓冲
	VencHeaderData sps_pps_data;//输出头部数据
	VencH264Param h264Param;//H.264 配置参数
	VencAllocateBufferParam bufferParam; //编码器缓冲参数
	VencH264FixQP fixQP;//适配量化参数 
	VencCyclicIntraRefresh sIntraRefresh;//帧间刷新
	struct inputbuf_addr* inputbuf_addr;
};
//初始化编码器
struct H264_encoder* H264_encoder_init(struct camera* camera);
//参数的意思为使用哪个编码器来编码哪个摄像头的图像，编码之后的写道那个文件去,这里仅编码一帧
int H264_encode_handle(struct H264_encoder* H264_encoder,FILE* fpH264,int channel_num);
//关闭编码器
int close_H264_encoder(struct H264_encoder* H264_encoder);
//写入头部
int H264_write_head(struct H264_encoder* H264_encoder,FILE* fpH264);
#endif