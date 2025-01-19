#include "Container_private.h"


/************************
    C A L L B A C K S
************************/
void
Container_resize(Node *node, Vec2Int dimensions)
{
    int        i;

    Container *self  = CONTAINER(node);
    Node      *child = node->child;
    
    int        orientation = self->orientation;
    int        direction   = self->order;

    Node_set_dimensions(node, dimensions);

    for (i = node->num_children; 0 < i; i--) {
        if (orientation == CONTAINER_VERTICAL) {
            dimensions.y -= Node_set_dimensions(child, dimensions).y;
            if (dimensions.y <= 0) break;
        } else {
            dimensions.x -= Node_set_dimensions(child, dimensions).x;
            if (dimensions.x <= 0) break;
        }
        child = child->siblings[direction];
    }
} /* Container_resize */
