#ifndef X265_H
#define X265_H

#define X265_PICTURE_WIDTH 640
#define X265_PICTURE_HEIGHT 480



extern unsigned char *x265_programmer_define_unsigned_char_point__picture_buffer;
extern unsigned long x265_programmer_define_unsigned_long__after_x265_size;


extern void x265_init(void);

extern void x265_picture_encode(void);
//extern void x265_picture_decode(void);

extern void x265_quit(void);







#endif
