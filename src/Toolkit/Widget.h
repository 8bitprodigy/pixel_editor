#ifndef WIDGET_H
#define WIDGET_H


#include "../AppState.h"
#include "../defs.h"


#define WIDGET( Self ) ((Widget *)(Self))


typedef struct Widget Widget;

/* Constructors */
void    Widget_init(  Widget *widget);
Widget *Widget_new(void);

/* Destructor */
void    Widget_free(  Widget *widget);

/* Callbacks */
void    Widget_update(Widget *widget, AppState *app_state);
void    Widget_draw(  Widget *widget, AppState *app_state);
void    Widget_event( Widget *widget, AppState *app_state);


#endif /* WIDGET_H */
