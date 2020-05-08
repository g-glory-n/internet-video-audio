/*
 * =================================================================================================
 * common.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_COMMON_H
#define PROGRAMMER_DEFINE_COMMON_H

/*
 * =================================================================================================
 * define global picture type and size(width height and the depth of a bit)
 * =================================================================================================
*/
#define PICTURE_TYPE YUYV
#define PICTURE_WIDTH 640
#define PICTURE_HEIGHT 480
#define PICTURE_BIT_DEPTH 2

#define SUCCESS 0
#define FAILURE -1

#define COMMON_PICTURE_TYPE PICTURE_TYPE
#define COMMON_PICTURE_WIDTH PICTURE_WIDTH
#define COMMON_PICTURE_HEIGHT PICTURE_HEIGHT
#define COMMON_PICTURE_BIT_DEPTH PICTURE_BIT_DEPTH



extern void common_init(void);
extern void common_refresh(void);



extern void common_quit(void);

#endif
