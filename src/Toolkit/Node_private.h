#ifndef NODE_PRIVATE_H
#define NODE_PRIVATE_H


#include <SDL2/SDL.h>

#include "Node.h"


typedef struct
Node
{
    struct Node *child;
    struct Node *parent;
    struct Node *siblings[2];

    uint8  num_children;
    uint8  depth;
    
    bool  damaged;
    
    uint16 width;
    uint16 height;
    bool   fill_width;
    bool   fill_height;
    Rect   rect;
    
    void    (*draw)(  struct Node *, SDL_Renderer *, AppState *);
    void    (*event)( struct Node *, SDL_Event,      AppState *);
    void    (*free)(  struct Node *);
    Vec2Int (*resize)(struct Node *, Vec2Int);
    void    (*update)(struct Node *, AppState *);
} Node;

/* Protected Methods */
void    Node_set_damaged(Node *node, bool damaged);
Vec2Int Node_set_dimensions(Node *node, Vec2Int dimensions);

#endif /* NODE_PRIVATE_H */
