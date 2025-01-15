#include "Node_private.h"


/****************************
    C O N S T R U C T O R
*****************************/
void  Node_init( Node *self )
{
    self->child   = NULL;
    self->parent  = NULL;
    self->prev    = self;
    self->next    = self;

    self->depth   = 0;
    self->rect    = (SDL_Rect){
        .x = 0, .y = 0,
        .w = 0, .h = 0,
    };
    self->damaged = true;

    self->update = NULL;
    self->draw   = NULL;
    self->event  = NULL;
    self->free   = NULL;
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
Node_free( Node *self )
{
    if(self->child) Node_free(self->child);
    if(self->next)  Node_free(self->next);
    if (self->free) self->free(self); 
    else free(self);
} /* Node_free */


/********************
    M E T H O D S
********************/
void
add_sibling(Node *self, Node *sibling)
{
    Node *last = self->prev;
    
    sibling->next = self;
    sibling->prev = last;

    self->prev = sibling;
    last->next = sibling;
}

void
Node_add_child(Node *self, Node *new_node)
{
    if (!self) return;
    if (!new_node) return;
    
    self->num_children++;
    new_node->parent = self;
    new_node->depth  = self->depth + 1;
    
    if (!self->child) {
        self->child      = new_node;
        return;
    }
    
    add_sibling(self->child, new_node);
}


/************************
    C A L L B A C K S
************************/
void
Node_update(Node *self, AppState *app_state)
{ 
    if(self->child)  Node_update(self->child, app_state);
    if(self->next)   Node_update(self->next, app_state);
    if(self->update) self->update(self, app_state);
}

void
Node_draw(Node *self, AppState *app_state)
{
    if(self->child) Node_draw(self->child, app_state);
    if(self->next)  Node_draw(self->next, app_state);
    if(self->draw)  self->draw(self, app_state);
}

void
Node_event(Node *self, AppState *app_state)
{
    if(self->child) Node_event(self->child, app_state);
    if(self->next)  Node_event(self->next, app_state);
    if(self->event) self->event(self, app_state);
}

