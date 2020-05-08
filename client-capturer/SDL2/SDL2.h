/*
 * =================================================================================================
 * SDL2.h
 * =================================================================================================
*/

#ifndef PROGRAMMER_DEFINE_SDL2_H
#define PROGRAMMER_DEFINE_SDL2_H

#include <SDL2/SDL.h>
#include "../common/common.h"

#define SUCCESS 0
#define FAILURE -1

#define SDL_WINDOW_WIDTH PICTURE_WIDTH
#define SDL_WINDOW_HEIGHT PICTURE_HEIGHT
#define SDL_PIXEL_WIDTH PICTURE_WIDTH
#define SDL_PIXEL_HEIGHT PICTURE_HEIGHT

#define SDL_FORMAT SDL_PIXELFORMAT_YUY2

extern SDL_Window *SDL_Window__point__window;
extern SDL_Renderer *SDL_Renderer__point__renderer;
extern SDL_Texture *SDL_Texture__point__texture;

extern unsigned char *SDL_programmer_define_undigned_char_point__picture_buffer;



extern void SDL2_init(void);

extern void SDL2_refresh(void);

extern void SDL2_quit(void);




#endif
