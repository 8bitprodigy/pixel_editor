

#include "Node_private.h"


/****************************
    C O N S T R U C T O R
*****************************/
void  Node_init( Node *node )
{
    node->child   = NULL;
    node->parent  = NULL;
    node->prev    = node;
    node->next    = node;

    node->depth   = 0;
    node->rect    = (SDL_Rect){
        .x = 0, .y = 0,
        .w = 0, .h = 0,
    };
    node->damaged = true;

    node->update = &Node_update;
    node->draw   = &Node_draw;
    node->event  = &Node_event;
    node->free   = &Node_free;
} /* Node_init */

Node *Node_new(void)
{
    Node *node = malloc(sizeof(Node));
    if (!node) {
        ERR_OUT("Failed to allocate memory for Node");
        return NULL;
    }

    Node_init(node);
    
    return node;
} /* Node_new */


/**************************
    D E S T R U C T O R
**************************/
void
Node_free( Node *node )
{
    if(node->child) node->child->free(node->child);
    if(node->next)  node->next->free(node->next);
    free(node);
} /* Node_free */


/********************
    M E T H O D S
********************/
void
add_sibling(Node *node, Node *sibling)
{
    Node *last = node->prev;
    
    sibling->next = node;
    sibling->prev = last;

    node->prev = sibling;
    last->next = sibling;
}

void
Node_add_child(Node *node, Node *new_node)
{
    if (!node) return;
    if (!new_node) return;
    
    node->num_children++;
    new_node->parent = node;
    
    if (!node->child) {
        node->child      = new_node;
        return;
    }
    
    add_sibling(node->child, new_node);
}


/************************
    C A L L B A C K S
************************/
void
Node_update(Node *node, AppState *app_state)
{ 
    if(node->child) node->child->update(node->child, app_state);
    if(node->next)  node->next->update(node->next, app_state);
}

void
Node_draw(Node *node, AppState *app_state)
{
    if(node->child) node->child->draw(node->child, app_state);
    if(node->next)  node->next->draw(node->next, app_state);
}

void
Node_event(Node *node, AppState *app_state)
{
    if(node->child) node->child->event(node->child, app_state);
    if(node->next)  node->next->event(node->next, app_state);
}
