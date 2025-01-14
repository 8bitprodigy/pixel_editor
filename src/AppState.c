#include <stdio.h>
#include <stdlib.h>

#include "AppState_private.h"


/****************************
    C O N S T R U C T O R    
****************************/
void
AppState_init(AppState *app_state)
{
    app_state->done        = false;
    app_state->app_width   = DEFAULT_SCREEN_WIDTH;
    app_state->app_height  = DEFAULT_SCREEN_HEIGHT;
    app_state->render_mode = SDL_RENDERER_SOFTWARE;
    app_state->damaged     = true;
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
AppState_free(AppState *app_state)
{
    SDL_DestroyWindow(app_state->window);
    SDL_Quit();
    free(app_state);
}


/********************
    M E T H O D S    
********************/
void
AppState_update(AppState *app_state)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            app_state->done = true;
        }
    }
}

void
AppState_draw(AppState *app_state)
{
    if (!app_state->damaged) return;

    SDL_Renderer *context = app_state->context;
/*
    if (SDL_MUSTLOCK(app_state->context)) {
        if (SDL_LockSurface(app_state->context) < 0) {
            SDL_ERR("Failed to lock surface");
            app_state->done = true;
        }
    }
    
    SDL_FillRect(app_state->context, NULL, SDL_MapRGB(app_state->context->format, 87, 87, 87));

    if (SDL_MUSTLOCK(app_state->context)) {
        SDL_UnlockSurface(app_state->context);
    }

    SDL_UpdateWindowSurface(app_state->window);
*/
    /* Clear the context with Grey */
    SDL_SetRenderDrawColor(context, 87, 87, 87, 255);
    SDL_RenderClear(context);
    
    SDL_SetRenderDrawColor(context, 255, 0, 0, 255);
    SDL_RenderFillRect(context, &(SDL_Rect){200, 120, 400, 240});

    /* Blit the updated context to the screen */
    SDL_RenderPresent(context);
    app_state->damaged = false;
}

void
AppState_run(AppState *app_state)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_ERR("Failed to initialize SDL");
        return;
    }

    app_state->window = SDL_CreateWindow(
        APP_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        app_state->app_width,
        app_state->app_height,
        SDL_WINDOW_SHOWN
    );
    if (!app_state->window) {
        SDL_ERR("Failed to create window");
        SDL_Quit();
        app_state->done = true;
        return;
    }
/*
    app_state->context = SDL_GetWindowSurface(app_state->window);
    if (!app_state->context) {
        SDL_ERR("Failed to get window surface");
        SDL_DestroyWindow(app_state->window);
        SDL_Quit();
        app_state->done = true;
        return;
    }
*/
    app_state->context = SDL_CreateRenderer(
        app_state->window, 
        -1, 
        app_state->render_mode | 
        SDL_RENDERER_PRESENTVSYNC
    );
    if (!app_state->context) {
        SDL_ERR("Failed to create SDL_Renderer");
        SDL_DestroyWindow(app_state->window);
        SDL_Quit();
        return;
    }
    
    app_state->damaged = true;
    while (!app_state->done){
        AppState_update(app_state);
        AppState_draw(app_state);
    }
}
