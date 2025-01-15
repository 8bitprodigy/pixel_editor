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

    uint num_children;
    uint depth;
    Rect rect;
    bool damaged;
    
    void (*update)(Node *, AppState *);
    void (*draw)(  Node *, AppState *);
    void (*event)( Node *, AppState *);
    void (*free)(  Node *);
} Node;


#endif /* NODE_PRIVATE_H */
