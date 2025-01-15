#ifndef WIDGET_PRIVATE_H
#define WIDGET_PRIVATE_H


#include "Node_private.h" /* Must go above `Widget.h` */
#include "Widget.h"


typedef struct
Widget
{
    Node base;
    SDL_Surface *surface;
} Widget;


#endif /* WIDGET_PRIVATE_H */
