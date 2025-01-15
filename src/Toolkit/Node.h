#ifndef NODE_H
#define NODE_H


#include "../AppState.h"
#include "../defs.h"


#define NODE( Self ) ((Node*)(Self))


typedef struct Node Node;

/* Constructors */
void  Node_init(  Node *node);
Node *Node_new(void);

/* Destructor */
void  Node_free(  Node *node);

/* Methods */
void Node_add_child(Node *node, Node *new_node);
void Node_remove_child(Node *node, Node *child_node);
int  Node_get_local_origin(Node *node);

/* Callbacks */
void  Node_update(Node *node, AppState *app_state);
void  Node_draw(  Node *node, AppState *app_state);
void  Node_event( Node *node, AppState *app_state);


#endif /* NODE_H */
