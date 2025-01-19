#ifndef CONTAINER_PRIVATE_H
#define CONTAINER_PRIVATE_H


#include "Node_private.h" /* Must go above `Container.h` */
#include "Container.h"


typedef struct
Container
{
    Node base;
    ContainerOrientation orientation;
    ContainerChildOrder  order;
} Container;


#endif
