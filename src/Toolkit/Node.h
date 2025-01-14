#ifndef NODE_H
#define NODE_H

#include "../AppState.h"
#include "../defs.h"

typedef struct Node Node;

/* Constructors */
void  Node_init(  Node *node);
Node *Node_new(void);

/* Destructor */
void  Node_free(  Node *node);

/* Methods */
void Node_add_child(Node *node, Node *new_node);
void Node_remove_child(Node *node, Node *child_node);

/* Callbacks */
void  Node_update(Node *node, AppState *);
void  Node_draw(  Node *node, AppState *);
void  Node_event( Node *node, AppState *);

#endif /* WIDGET_H */
