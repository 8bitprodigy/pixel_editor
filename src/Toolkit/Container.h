#ifndef CONTAINER_H
#define CONTAINER_H


#include "../AppState.h"
#include "../defs.h"


#define CONTAINER( Self ) ((Container*)(Self))


typedef struct Container Container;

/* Constructors */
void       Container_init(  Container *container);
Container *Container_new(void);

/* Destructor */
void       Container_free(  Container *container);

/* Callbacks */
void       Container_update(Container *container, AppState *app_state);
void       Container_draw(  Container *container, AppState *app_state);
void       Container_event( Container *container, AppState *app_state);


#endif /* CONTAINER_H */
