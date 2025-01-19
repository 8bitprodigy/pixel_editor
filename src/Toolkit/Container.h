#ifndef CONTAINER_H
#define CONTAINER_H


#include "Node.h"


#define CONTAINER( Self ) ((Container*)(Self))


typedef enum {
    CONTAINER_VERTICAL,  
    CONTAINER_HORIZONTAL,
}
ContainerOrientation;

typedef enum {
    CONTAINER_ASCENDING,
    CONTAINER_DESCENDING,
}
ContainerChildOrder;


typedef struct Container Container;


/* Constructors */
void       Container_init(  Container *container);
Container *Container_new(void);

/* Destructor */
void       Container_free(  Container *container);

/* Callbacks */
void       Container_draw(  Node *container, SDL_Renderer *context,    AppState *app_state);
void       Container_event( Node *container, SDL_Event     event,      AppState *app_state);
void       Container_resize(Node *container, Vec2Int       dimensions);
void       Container_update(Node *container, AppState     *app_state);


#endif /* CONTAINER_H */
