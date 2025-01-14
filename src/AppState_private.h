#ifndef APPSTATE_PRIVATE_H
#define APPSTATE_PRIVATE_H

#include <SDL2/SDL.h>

#include "AppState.h"

typedef struct
AppState
{
    bool          done;
    uint          app_width;
    uint          app_height;
    SDL_Window   *window;
    int32         render_mode;
    SDL_Renderer *context;
    bool          damaged;
} AppState;

#endif /* APPSTATE_PRIVATE_H */
