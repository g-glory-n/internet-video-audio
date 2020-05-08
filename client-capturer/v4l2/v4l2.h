/*
 * =================================================================================================
 * v4l2.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_V4L2_H
#define PROGRAMMER_DEFINE_V4L2_H

#include <linux/videodev2.h>
#include "../common/common.h"

#define V4L2_PICTURE_WIDTH PICTURE_WIDTH
#define V4L2_PICTURE_HEIGHT PICTURE_HEIGHT

#define V4L2_DEVICE "/dev/video0"

#define SUCCESS 0
#define FAILURE -1

struct v4l2_programmer_define_struct__picture_queue_struct
{
        void *start;
        unsigned int length;
};

extern struct v4l2_buffer v4l2_buffer__dqbuf_qbuf;

extern struct v4l2_programmer_define_struct__picture_queue_struct *v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer; 
// v4l2_programmer_define_struct_point__picture_queue_struct__picture_buffer[v4l2_buffer__dqbuf_qbuf.index].start // saved picture data

extern int v4l2_programmer_define_signed_int__fd;


extern void v4l2_init(void);

extern void v4l2_refresh(void);

extern void v4l2_quit(void);



















#endif
