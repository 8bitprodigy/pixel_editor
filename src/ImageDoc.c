#include <SDL2/SDL.h>

#include "ImageDoc.h"
#include "types.h"


typedef struct
ImageDoc
{
    struct ImageDoc *prev;
    struct ImageDoc *next;
    
    char     *name;
    char     *save_path;
    
    Image     image;
    
    Color     palette[256];
    uint8     palette_size;
    uint8     active_colors[2];
    /* TODO: pointer to current tool or something */
} ImageDoc;


