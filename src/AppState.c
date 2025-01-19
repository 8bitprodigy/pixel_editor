#include <stdio.h>
#include <stdlib.h>


#include <SDL2/SDL.h>

#include "AppState.h"
#include "Toolkit/Toolkit.h"


/****************************************
    S T R U C T   D E F I N I T I O N
****************************************/
typedef struct
AppState
{
    bool          done;
    uint16        app_width;
    uint16        app_height;
    SDL_Window   *window;
    int32         render_mode;
    SDL_Renderer *context;
    bool          damaged;
    Node         *UI;
} AppState;


/****************************
    C O N S T R U C T O R    
****************************/
void
AppState_init(AppState *self)
{
    self->done        = false;
    self->app_width   = DEFAULT_SCREEN_WIDTH;
    self->app_height  = DEFAULT_SCREEN_HEIGHT;
    self->render_mode = SDL_RENDERER_SOFTWARE;
    self->damaged     = true;
}

AppState *
AppState_new(void)
{
    AppState *app_state = malloc(sizeof(AppState));
    if (!app_state) {
        ERR_OUT("Failed to allocate memory for AppState.");
        return NULL;
    }

    AppState_init(app_state);
    
    return app_state;
}


/**************************
    D E S T R U C T O R
**************************/
void
AppState_free(AppState *self)
{
    SDL_DestroyWindow(self->window);
    SDL_Quit();
    free(self);
}


/********************
    M E T H O D S    
********************/
void
AppState_update(AppState *self)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            self->done = true;
        }
        Node_event(self->UI, event, self);
    }
    Node_update(self->UI, self);
}

void
AppState_draw(AppState *self)
{
    if (!self->damaged) return;

    SDL_Renderer *context = self->context;

    /* Clear the context with Grey */
    SDL_SetRenderDrawColor(context, 87, 87, 87, 255);
    SDL_RenderClear(context);
    /* Red Rectangle */
    SDL_SetRenderDrawColor(context, 255, 0, 0, 255);
    SDL_RenderFillRect(context, &(SDL_Rect){200, 120, 400, 240});

    Node_draw(self->UI, context, self);
    /* Blit the updated context to the screen */
    SDL_RenderPresent(context);
    self->damaged = false;
}

void
AppState_run(AppState *self)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_ERR("Failed to initialize SDL");
        return;
    }

    self->window = SDL_CreateWindow(
        APP_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        self->app_width,
        self->app_height,
        SDL_WINDOW_SHOWN
    );
    if (!self->window) {
        SDL_ERR("Failed to create window");
        SDL_Quit();
        self->done = true;
        return;
    }

    self->context = SDL_CreateRenderer(
        self->window, 
        -1, 
        self->render_mode | 
        SDL_RENDERER_PRESENTVSYNC
    );
    if (!self->context) {
        SDL_ERR("Failed to create SDL_Renderer");
        SDL_DestroyWindow(self->window);
        SDL_Quit();
        return;
    }
    
    self->damaged = true;
    while (!self->done){
        AppState_update(self);
        AppState_draw(self);
    }
}
