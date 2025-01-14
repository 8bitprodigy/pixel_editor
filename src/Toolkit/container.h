#ifndef CONTAINER_H
#define CONTAINER_H

#include "../AppState.h"
#include "../defs.h"

typedef struct Container Container;

/* Constructors */
void  Container_init(  Container *node);
Container *Container_new(void);

/* Destructor */
void  Container_free(  Container *node);

/* Callbacks */
void  Container_update(Container *node, AppState *);
void  Container_draw(  Container *node, AppState *);
void  Container_event( Container *node, AppState *);

#endif /* CONTAINER_H */
