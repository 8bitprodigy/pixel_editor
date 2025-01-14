#ifndef APPSTATE_H
#define APPSTATE_H

#include "defs.h"

typedef struct AppState AppState;

/* Contstructors */
void AppState_init(  AppState *app_state);
AppState *AppState_new(void);

/* Destructor */
void AppState_free(  AppState *app_state);

/* Methods */
void AppState_update(AppState *app_state);
void AppState_draw(  AppState *app_state);
void AppState_run(   AppState *app_state);

#endif /* APPSTATE_H */
