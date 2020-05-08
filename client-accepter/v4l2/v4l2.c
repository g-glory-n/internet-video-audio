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

#include "v4l2.h"

struct v4l2_buffer v4l2_buffer__dqbuf_qbuf;
struct v4l2_programmer_define_struct__picture_queue_struct *v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer;

signed int v4l2_programmer_define_signed_int__fd = 0;
unsigned char v4l2_programmer_define_unsigned_char__request_buffers_count = 0;

void v4l2_init(void)
{
	printf("\nV4L2:\n");
	memset(&v4l2_buffer__dqbuf_qbuf, '\0', sizeof(v4l2_buffer__dqbuf_qbuf));

        if((v4l2_programmer_define_signed_int__fd = open(V4L2_DEVICE, O_RDWR)) == -1)
        {
                printf("\nv4l2: open device failed ! -> open();\n");
                exit(FAILURE);
        }

        printf("\ndisplay v4l2 file-descriptor number:\n");
        printf("\tfile-descriptor-number: %d\n", v4l2_programmer_define_signed_int__fd);
/*
 * =================================================================================================
 * query device properties
 * =================================================================================================
*/
        printf("\ndevice properties: \n");
        struct v4l2_capability v4l2_capability__query_properties;
        if(ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_QUERYCAP, &v4l2_capability__query_properties) == -1)
        {
                printf("\nv4l2: query device properties failed ! -> ioctl();\n");
                exit(FAILURE);
        }
        printf("\tdrive: %s\n", v4l2_capability__query_properties.driver);
        printf("\tcard: %s\n", v4l2_capability__query_properties.card);
        printf("\tbus_info: %s\n", v4l2_capability__query_properties.bus_info);
        printf("\tversion: %u\n", v4l2_capability__query_properties.version);
        printf("\tcapabilities: %u\n", v4l2_capability__query_properties.capabilities);

        if((v4l2_capability__query_properties.capabilities & V4L2_CAP_VIDEO_CAPTURE) == V4L2_CAP_VIDEO_CAPTURE)
                printf("\tdevice support video capture ! -> V4L2_CAP_VIDEO_CAPTURE\n");
        if((v4l2_capability__query_properties.capabilities & V4L2_CAP_STREAMING) == V4L2_CAP_STREAMING)
                printf("\tdevice support streaming ! -> V4L2_CAP_STREAMING\n");
/*
 * =================================================================================================
 * query and display all supported formats
 * =================================================================================================
*/
        printf("\nlist all support format: \n");
        struct v4l2_fmtdesc v4l2_fmtdesc__query_support_format;
        v4l2_fmtdesc__query_support_format.index = 0;
        v4l2_fmtdesc__query_support_format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        while(ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_ENUM_FMT, &v4l2_fmtdesc__query_support_format) != -1)
        {
                printf("\t%d. %s\n", v4l2_fmtdesc__query_support_format.index+1, v4l2_fmtdesc__query_support_format.description);
                v4l2_fmtdesc__query_support_format.index++;
        }
/*
 * =================================================================================================
 * set pixel format
 * =================================================================================================
*/
        printf("\nseting device pixel format:\n\t......\n");
        struct v4l2_format v4l2_format__set_format;
        v4l2_format__set_format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        v4l2_format__set_format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
        v4l2_format__set_format.fmt.pix.width = V4L2_PICTURE_WIDTH;
        v4l2_format__set_format.fmt.pix.height = V4L2_PICTURE_HEIGHT;
        v4l2_format__set_format.fmt.pix.field = V4L2_FIELD_INTERLACED;

        if(ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_S_FMT, &v4l2_format__set_format) == -1)
        {
                printf("\nv4l2: set format failed ! -> ioctl();\n");
                exit(FAILURE);
        }
        printf("\tsuccessful !\n");
/*
 * =================================================================================================
 * display current format
 * =================================================================================================
*/
        printf("\ncurrent data format:\n");
        struct v4l2_format v4l2_format__query_current_format;
        v4l2_format__query_current_format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_G_FMT, &v4l2_format__query_current_format);
        printf("\twidth: %d\n\thigh: %d\n", v4l2_format__query_current_format.fmt.pix.width, v4l2_format__query_current_format.fmt.pix.height);

//      struct v4l2_fmtdesc v4l2_fmtdesc__query_support_format;
        v4l2_fmtdesc__query_support_format.index = 0;
        v4l2_fmtdesc__query_support_format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        while(ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_ENUM_FMT, &v4l2_fmtdesc__query_support_format) != -1)
        {
                if(v4l2_fmtdesc__query_support_format.pixelformat & v4l2_format__query_current_format.fmt.pix.pixelformat)
                {
                        printf("\tformat: %s\n", v4l2_fmtdesc__query_support_format.description);
                        break;
                }
                v4l2_fmtdesc__query_support_format.index++;
        }

/*
 * =================================================================================================
 * check whether a type frame format is supported
 * =================================================================================================*/
        printf("\ncheck whether a type frame format is supported:\n");
        printf("\tchecking RGB32:\n");
        struct v4l2_format v4l2_format__one_type_format_whether_support_or_not;
        v4l2_format__one_type_format_whether_support_or_not.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        v4l2_format__one_type_format_whether_support_or_not.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB32;
        if(ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_TRY_FMT, &v4l2_format__one_type_format_whether_support_or_not) == -1)
                if(errno == EINVAL)
                        printf("\tdon't support the RGB32 format !\n");
                else
                {}
        else
                printf("\tsupport the RGB32 format !\n");
/*
 * =================================================================================================
 *
 * =================================================================================================
*/

        putchar('\n');








/*
 * =================================================================================================
 * request buffers
 * =================================================================================================
*/
        struct v4l2_requestbuffers v4l2_requestbuffers__request_buffers;
	v4l2_requestbuffers__request_buffers.count = 1/*4*/; //one request buffer can reduse delay!
	v4l2_programmer_define_unsigned_char__request_buffers_count = v4l2_requestbuffers__request_buffers.count;
        v4l2_requestbuffers__request_buffers.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        v4l2_requestbuffers__request_buffers.memory = V4L2_MEMORY_MMAP;
        if(ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_REQBUFS, &v4l2_requestbuffers__request_buffers))
        {
                printf("\nv4l2: request buffers failed ! -> ioctl();\n");
                exit(FAILURE);
        }
/*
 * =================================================================================================
 * mmap every buffer to user-space
 * =================================================================================================
*/
//	struct v4l2_programmer_define_struct__picture_queue_struct *v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer;
//	struct v4l2_buffer v4l2_buffer__dqbuf_qbuf;
//
        unsigned char v4l2_programmer_define_unsigned_char__for_i0 = 0;
        v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer = (struct v4l2_programmer_define_struct__picture_queue_struct *)malloc(v4l2_requestbuffers__request_buffers.count*sizeof(*v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer));
        memset(v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer, '\0', sizeof(v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer));
	if(NULL == v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer)
        {
                printf("\nv4l2: alloc memory failed ! -> (struct buffer *)malloc(v4l2_request_buffers.count*sizeof(*v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer));\n");
                exit(FAILURE);
        }
        for(v4l2_programmer_define_unsigned_char__for_i0 = 0; v4l2_programmer_define_unsigned_char__for_i0 < v4l2_requestbuffers__request_buffers.count; v4l2_programmer_define_unsigned_char__for_i0++)
        {
                v4l2_buffer__dqbuf_qbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
                v4l2_buffer__dqbuf_qbuf.memory = V4L2_MEMORY_MMAP;
                v4l2_buffer__dqbuf_qbuf.index = v4l2_programmer_define_unsigned_char__for_i0;
                if(ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_QUERYBUF, &v4l2_buffer__dqbuf_qbuf) == -1)
                {
                        printf("\nquery buffer failed ! -> ioctl(int v4l2_programmer_define_signed_int__fd, int VIDIOC_QUERYBUF, struct v4l2_buffer *v4l2_buffer__dqbuf_qbuf);\n");
                        exit(FAILURE);
                }
                v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_programmer_define_unsigned_char__for_i0].length = v4l2_buffer__dqbuf_qbuf.length;
                v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_programmer_define_unsigned_char__for_i0].start = mmap(NULL, v4l2_buffer__dqbuf_qbuf.length, PROT_READ | PROT_WRITE, MAP_SHARED, v4l2_programmer_define_signed_int__fd, v4l2_buffer__dqbuf_qbuf.m.offset);
                if(v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_programmer_define_unsigned_char__for_i0].start == MAP_FAILED)
                {
                        printf("\nmap buffer failed ! -> mmap(void *start, size_t length, int port, int flags, int fd, off_t offset);\n");
                        exit(FAILURE);
                }
	}
/*
 * =================================================================================================
 * fill number of v4l2_request_buffers.count buffers
 * =================================================================================================
*/
        for(v4l2_programmer_define_unsigned_char__for_i0 = 0; v4l2_programmer_define_unsigned_char__for_i0 < v4l2_requestbuffers__request_buffers.count; v4l2_programmer_define_unsigned_char__for_i0++)
        {
                v4l2_buffer__dqbuf_qbuf.index = v4l2_programmer_define_unsigned_char__for_i0;
                ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_QBUF, &v4l2_buffer__dqbuf_qbuf);
        }
/*
 * =================================================================================================
 * begin to capture video
 * =================================================================================================
*/
        enum v4l2_buf_type v4l2_buf_type__capture;
        v4l2_buf_type__capture = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_STREAMON, &v4l2_buf_type__capture);
}




void v4l2_refresh(void)
{
        v4l2_buffer__dqbuf_qbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        v4l2_buffer__dqbuf_qbuf.memory = V4L2_MEMORY_MMAP;
        ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_DQBUF, &v4l2_buffer__dqbuf_qbuf);

        v4l2_buffer__dqbuf_qbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        v4l2_buffer__dqbuf_qbuf.memory = V4L2_MEMORY_MMAP;
        ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_QBUF, &v4l2_buffer__dqbuf_qbuf);
}



void v4l2_quit(void)
{
	unsigned char v4l2_programmer_define_unsigned_char__for_i0 = 0;
        for(v4l2_programmer_define_unsigned_char__for_i0 = 0; v4l2_programmer_define_unsigned_char__for_i0 < v4l2_programmer_define_unsigned_char__request_buffers_count; v4l2_programmer_define_unsigned_char__for_i0++)
	{
		munmap(v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_programmer_define_unsigned_char__for_i0].start, v4l2_buffer__dqbuf_qbuf.length);
	}
	enum v4l2_buf_type v4l2_buffer_type_capture;
	v4l2_buffer_type_capture = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	ioctl(v4l2_programmer_define_signed_int__fd, VIDIOC_STREAMOFF, &v4l2_buffer_type_capture);
	close(v4l2_programmer_define_signed_int__fd);
}


