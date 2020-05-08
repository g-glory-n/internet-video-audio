/*
 * =================================================================================================
 * udp.cpp
 * =================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <iostream>

#ifdef ENABLE_STATIC
#ifdef X86_64

#endif
#ifdef ARM_64

#endif
#endif

#ifdef ENABLE_SHARED

#endif

#include "include/rtpsession.h"
#include "include/rtpudpv4transmitter.h"
#include "include/rtpipv4address.h"
#include "include/rtpsessionparams.h"
#include "include/rtperrors.h"
#include "include/rtplibraryversion.h"

#include "jrtp.h"
#include "../../x264/x264.h"


using namespace jrtplib;



RTPSession RTPSession__session;
uint16_t rtp_programmer_define_uint16_t__portbase = 1024;
uint16_t rtp_programmer_define_uint16_t__destport = 1024;
uint32_t rtp_programmer_define_uint32_t__destip = 0;
std::string rtp_programmer_define_string__ipstr = "192.168.1.240";


//signed int rtp_programmer_define_signed_int__check_error = 0;

unsigned char *rtp_programmer_define_unsigned_char_point__picture_buffer;
unsigned long rtp_programmer_define_unsigned_long_point__compressed_size;
unsigned long rtp_programmer_define_unsigned_long__size_of_send;







static void rtp_check_error(signed int rtp_programmer_define_signed_int__check_error)
{
//	using namespace jrtplib;
//	using namespace std;
	if(rtp_programmer_define_signed_int__check_error < 0)
	{
		std::string rtp_programmer_define_string__string = jrtplib::RTPGetErrorString(rtp_programmer_define_signed_int__check_error);
		std::cout << "\nrtp error: " << rtp_programmer_define_string__string << "\n" << std::endl;
		exit(FAILURE);
	}
}


void rtp_init(void)
{
	rtp_programmer_define_unsigned_char_point__picture_buffer = x264_programmer_define_unsigned_char_point__picture_buffer;
	rtp_programmer_define_unsigned_long_point__compressed_size = x264_programmer_define_unsigned_long__after_x264_size;





/*
 * =================================================================================================
 * set the necessary information(port ip-address and so on)
 * =================================================================================================
*/
	std::cout << "rtp version: " << RTPLibraryVersion::GetVersion().GetVersionString() << std::endl;
	rtp_programmer_define_uint32_t__destip = inet_addr(rtp_programmer_define_string__ipstr.c_str());
	if (rtp_programmer_define_uint32_t__destip == INADDR_NONE)
	{
		std::cerr << "bad IP address specified" << std::endl;
		exit(FAILURE);
	}

// The inet_addr function returns a value in network byte order, but
// we need the IP address in host byte order, so we use a call to
// ntohl
	rtp_programmer_define_uint32_t__destip = ntohl(rtp_programmer_define_uint32_t__destip);

// Now, we'll create a RTP session, set the destination, send some
// packets and poll for incoming data.




// 1: 初始化
// 在使用 JRTPLIB 进行实时流媒体数据传输之前, 首先应该生成 RTPSession 类的一个实例来表示此次 RTP会话, 然后调用 Create() 方法来对其进行初始化操作. RTPSession 类的 Create() 方法只有一个参数, 用来指明此次 RTP 会话所采用的端口号.
// RTPSession sess;
// sess.Create(5000);

// JRTPLIB-3.7中已经修改了Create(prot)方法. 新的Create方法被修改为Create(sessparams,&transparams). 其中的两个参数需要如下先定义:
// RTPUDPv4TransmissionParams transparams;
// RTPSessionParams sessparams;
// sessparams.SetOwnTimestampUnit(1.0/8000.0);/*设置时间戳，1/8000表示1秒钟采样8000次，即录音时的8KHz*/
// sessparams.SetAcceptOwnPackets(true);
// transparams.SetPortbase(portbase);/*本地通讯端口*/

	RTPUDPv4TransmissionParams RTPUDPv4TransmissionParams__transfer_params;
	RTPSessionParams RTPSessionParams__session_params;

// IMPORTANT: The local timestamp unit MUST be set, otherwise
//            RTCP Sender Report info will be calculated wrong
// In this case, we'll be sending 10 samples each second, so we'll
// put the timestamp unit to (1.0/10.0)
	RTPSessionParams__session_params.SetOwnTimestampUnit(1.0/30.0);
	RTPSessionParams__session_params.SetAcceptOwnPackets(true);
	RTPUDPv4TransmissionParams__transfer_params.SetPortbase(rtp_programmer_define_uint16_t__portbase);


// 2: 数据发送准备
// 当 RTP 会话成功建立起来之后, 接下去就可以开始进行流媒体数据的实时传输了. 首先需要设置好数据发送的目标地址, RTP 协议允许同一会话存在多个目标地址, 这可以通过调用 RTPSession 类的 AddDestination() DeleteDestination() 和 ClearDestinations() 方法来完成. 例如, 下面的语句表示的是让 RTP 会话将数据发送到本地主机的 6000 端口:
// unsigned long addr = ntohl(inet_addr("127.0.0.1")); 
// sess.AddDestination(addr, 6000);

	signed int rtp_programmer_define_signed_int__check_error = RTPSession__session.Create(RTPSessionParams__session_params, &RTPUDPv4TransmissionParams__transfer_params);
	rtp_check_error(rtp_programmer_define_signed_int__check_error);

	RTPIPv4Address addr(rtp_programmer_define_uint32_t__destip,rtp_programmer_define_uint16_t__destport); //?

	rtp_programmer_define_signed_int__check_error = RTPSession__session.AddDestination(addr);
	rtp_check_error(rtp_programmer_define_signed_int__check_error);


	RTPSession__session.SetDefaultPayloadType(0);
	RTPSession__session.SetDefaultMark(false);  
	RTPSession__session.SetDefaultTimestampIncrement(30);

}




void rtp_send(void)
{
/*
 * =================================================================================================
 * set the size of data, send and print the data
 * =================================================================================================
*/
	rtp_programmer_define_unsigned_long_point__compressed_size = x264_programmer_define_unsigned_long__after_x264_size;
	
// 3: 数据发送
// 目标地址全部指定之后, 接着就可以调用 RTPSession 类的 SendPacket() 方法, 向所有的目标地址发送流媒体数据. SendPacket() 是 RTPSession 类提供的一个重载函数对于同一个 RTP 会话来讲, 负载类型, 标识和时戳增量通常来讲都是相同的, JRTPLIB 允许将它们设置为会话的默认参数, 这是通过调用 RTPSession 类的 SetDefaultPayloadType() SetDefaultMark() 和 SetDefaultTimeStampIncrement() 方法来完成的. 为 RTP 会话设置这些默认参数的好处是可以简化数据的发送, 例如: 如果为 RTP 会话设置了默认参数:
// 
// RTPSession__session.SetDefaultPayloadType(0);
// RTPSession__session.SetDefaultMark(false);  
// RTPSession__session.SetDefaultTimestampIncrement(10);
// 
// 之后在进行数据发送时只需指明要发送的数据及其长度就可以了:
// 
// RTPSession__session.SendPacket(buffer, 5);
// 
// 在真正的语音传输中, 上面的buffer就是我们录音时所得到的buffer. 使用上面的函数可以简单的发送, 但无法真正的实现RTP传输, 我们需要调用另一个接口: sess.SendPacket((void *)buffer, sizeof(buffer), 0, false, 8000); 详细的说明可以查看JRTPLIB的说明文档.

//	signed int rtp_programmer_define_signed_int__check_error = RTPSession__session.SendPacket((void *)rtp_programmer_define_unsigned_char_point__picture_buffer, rtp_programmer_define_unsigned_long_point__compressed_size, 0, false, 30);
	
	signed int rtp_programmer_define_signed_int__check_error = RTPSession__session.SendPacket(rtp_programmer_define_unsigned_char_point__picture_buffer, rtp_programmer_define_unsigned_long_point__compressed_size);
	rtp_check_error(rtp_programmer_define_signed_int__check_error);

	fprintf(stdout, "sended data which size is %ld\n", rtp_programmer_define_unsigned_long_point__compressed_size);	
		
//	RTPTime::Wait(RTPTime(1,0));
}




void rtp_receive(void)
{
	
}




void rtp_quit(void)
{
	
}







