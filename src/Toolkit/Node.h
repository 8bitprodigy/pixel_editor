#ifndef NODE_H
#define NODE_H


#include <SDL2/SDL.h>

#include "../AppState.h"
#include "../defs.h"
#include "../types.h"


#define NODE( Self ) ((Node*)(Self))


typedef enum {
    NODE_PREV,
    NODE_NEXT,
}
NodeSiblingDirection;


typedef struct Node Node;

/* Constructors */
void  Node_init(  Node *node);
Node *Node_new(void);

/* Destructor */
void  Node_free(  Node *node);

/* Methods */
void Node_add_child(       Node *node, Node *new_node);
void Node_remove_child(    Node *node, Node *child_node);
int  Node_get_local_origin(Node *node);

/* Callbacks */
void     Node_draw(  Node *node, SDL_Renderer *context,    AppState *app_state);
void     Node_event( Node *node, SDL_Event     event,      AppState *app_state);
Vec2Int  Node_resize(Node *node, Vec2Int       dimensions);
void     Node_update(Node *node, AppState     *app_state);


#endif /* NODE_H */
