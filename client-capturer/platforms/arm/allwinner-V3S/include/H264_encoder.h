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
	VideoEncoder* VideoEnc;//������
	VencBaseConfig baseConfig;//��������������
	VencInputBuffer inputBuffer;//�������뻺��
	VencOutputBuffer outputBuffer;//�����������
	VencHeaderData sps_pps_data;//���ͷ������
	VencH264Param h264Param;//H.264 ���ò���
	VencAllocateBufferParam bufferParam; //�������������
	VencH264FixQP fixQP;//������������ 
	VencCyclicIntraRefresh sIntraRefresh;//֡��ˢ��
	struct inputbuf_addr* inputbuf_addr;
};
//��ʼ��������
struct H264_encoder* H264_encoder_init(struct camera* camera);
//��������˼Ϊʹ���ĸ��������������ĸ�����ͷ��ͼ�񣬱���֮���д���Ǹ��ļ�ȥ,���������һ֡
int H264_encode_handle(struct H264_encoder* H264_encoder,FILE* fpH264,int channel_num);
//�رձ�����
int close_H264_encoder(struct H264_encoder* H264_encoder);
//д��ͷ��
int H264_write_head(struct H264_encoder* H264_encoder,FILE* fpH264);
#endif