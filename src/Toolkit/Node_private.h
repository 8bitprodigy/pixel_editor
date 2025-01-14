#ifndef NODE_PRIVATE_H
#define NODE_PRIVATE_H

#include <SDL2/SDL.h>

#include "Node.h"


typedef struct
Node
{
    struct Node *child;
    struct Node *parent;
    struct Node *next;
    struct Node *prev;
    
    SDL_Rect rect;
    
    void (*update)(Node *, AppState *);
    void (*draw)(  Node *, AppState *);
    void (*event)( Node *, AppState *);
} Node;


#endif /* NODE_PRIVATE_H */
