/*
 * =================================================================================================
 * SDL2.c
 * =================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>

#include <SDL2/SDL.h>

#include <linux/videodev2.h>

#include "SDL2.h"
#include "../v4l2/v4l2.h"
#include "../ffmpeg/ffmpeg.old.h"

SDL_Window *SDL_Window__point__window = NULL;
SDL_Renderer *SDL_Renderer__point__renderer = NULL;
SDL_Texture *SDL_Texture__point__texture = NULL;

unsigned char *SDL_programmer_define_undigned_char_point__picture_buffer = NULL;

void SDL2_init(void)
{
	SDL_programmer_define_undigned_char_point__picture_buffer = ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode;

        SDL_Window__point__window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
        if(NULL == SDL_Window__point__window)
        {
                fprintf(stdout, "create window failed !\n");
                exit(-1);
        }
        SDL_Renderer__point__renderer = SDL_CreateRenderer(SDL_Window__point__window, -1, SDL_RENDERER_ACCELERATED);
        if(NULL == SDL_Renderer__point__renderer)
        {
                fprintf(stdout, "create renderer failed !\n");
                exit(-1);
        }
        SDL_Texture__point__texture = SDL_CreateTexture(SDL_Renderer__point__renderer, SDL_FORMAT, SDL_TEXTUREACCESS_STREAMING, SDL_PIXEL_WIDTH, SDL_PIXEL_HEIGHT);
        if(NULL == SDL_Texture__point__texture)
        {
                fprintf(stdout, "create texture failed !\n");
                exit(-1);
        }
}


void SDL2_refresh(void)
{
//	SDL_programmer_define_undigned_char_point__picture_buffer = ffmpeg_old_programmer_define_unsigned_char_point__picture_buffer_after_ffmpeg_old_decode;

	SDL_UpdateTexture(SDL_Texture__point__texture, NULL, SDL_programmer_define_undigned_char_point__picture_buffer, SDL_PIXEL_WIDTH*2);
	SDL_RenderClear(SDL_Renderer__point__renderer);
        SDL_RenderCopy(SDL_Renderer__point__renderer, SDL_Texture__point__texture, NULL, NULL);
        SDL_RenderPresent(SDL_Renderer__point__renderer);
}


void SDL2_quit(void)
{
        SDL_DestroyTexture(SDL_Texture__point__texture);
        SDL_DestroyRenderer(SDL_Renderer__point__renderer);
        SDL_DestroyWindow(SDL_Window__point__window);
        SDL_Quit();
}




