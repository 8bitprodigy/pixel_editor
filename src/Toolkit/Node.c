#include "Node_private.h"


/****************************
    C O N S T R U C T O R
*****************************/
void  Node_init( Node *self )
{
    self->prev    = self;
    self->next    = self;
    self->child   = NULL;
    self->parent  = NULL;

    self->depth   = 0;
    self->rect    = (SDL_Rect){
        .x = 0, .y = 0,
        .w = 0, .h = 0,
    };
    self->damaged = true;

    self->update = NULL;
    self->draw   = NULL;
    self->event  = NULL;
    self->free   = &Node_free;
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
} /* add_sibling */

void
Node_add_child(Node *self, Node *new_node)
{
    if (!self) return;
    if (!new_node) return;
    
    self->num_children++;
    new_node->parent = self;
    new_node->depth  = self->depth + 1;
    
    if (!self->child) {
        self->child = new_node;
        return;
    }
    
    add_sibling(self->child, new_node);
} /* Node_add_child */


/****************************************
    P R O T E C T E D   M E T H O D S
****************************************/
void
Node_set_damaged(Node *self, bool damaged)
{
    self->damaged = damaged;
    if (!damaged) return;
    
    Node_set_damaged(self->parent, damaged);
} /* Node_set_damaged */

Vec2Int
Node_set_dimensions(Node *self, Vec2Int dimensions)
{
    Rect    *rect      = &self->rect;
    Vec2Int  final_dim;
    
    self->damaged = true;

    if (self->fill_width)  final_dim.x = dimensions.x;
    else                   final_dim.x = self->width;
    if (self->fill_height) final_dim.y = dimensions.y;
    else                   final_dim.y = self->height;

    rect->w = final_dim.x;
    rect->h = final_dim.y;

    return final_dim;
} /* Node_set_dimensions */


/************************
    C A L L B A C K S
************************/
void
Node_draw(Node *self, SDL_Renderer *context, AppState *app_state)
{
    if (!self) return;
    Node_draw( self->siblings[NODE_NEXT], context, app_state);
    if (!self->damaged) return;
    Node_draw( self->child, context, app_state);
    if (self->draw)  self->draw(self,     context, app_state);
} /* Node_draw */

void
Node_event(Node *self, SDL_Event event, AppState *app_state)
{
    if (!self) return;
    Node_event(self->siblings[NODE_NEXT], event, app_state);
    Node_event(self->child, event, app_state);
    if (self->event) self->event(self,    event, app_state);
} /* Node_event */

Vec2Int
Node_resize(Node *self, Vec2Int dimensions)
{ 
    if (!self) return dimensions;
    if (self->resize) return self->resize(self, dimensions);
} /* Node_resize */

void
Node_update(Node *self, AppState *app_state)
{ 
    if (!self) return;
    Node_update(self->siblings[NODE_NEXT], app_state);
    Node_update(self->child, app_state);
    if (self->update) self->update(self,   app_state);
} /* Node_update */
