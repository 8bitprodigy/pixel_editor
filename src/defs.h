/* Common `#define`s go here */
#ifndef DEFS_H
#define DEFS_H

#include <stdint.h>
/* CONSTANTS */
#define DEFAULT_SCREEN_WIDTH  800
#define DEFAULT_SCREEN_HEIGHT 480
#define APP_NAME "Pixel Editor" /* To be changed */

/* TYPES */
#define uint8  unsigned char 
#define int16  int_least16_t
#define uint16 uint_least16_t
#define int32  uint_least32_t
#define bool  unsigned char
#define false 0
#define true  !false


#define Rect SDL_Rect
#define RECT( _x_, _y_, _w_, _h_ ) ((Rect){.x=(_x_),.y=(_y_),.w=(_w_),.h=(_h_))

/* FUNCTIONS */
#define ERR_OUT( Error_Text ) perror( "[ERROR] " Error_Text "\n" )
#define SDL_ERR( Error_Text ) printf( "[SDL ERROR] " Error_Text ": %s\n", SDL_GetError() )

#endif /* DEFS_H */
