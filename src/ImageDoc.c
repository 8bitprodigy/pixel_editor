#include <SDL2/SDL.h>

#include "ImageDoc.h"


/****************************************
    S T R U C T   D E F I N I T I O N
****************************************/
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


/****************************
    C O N S T R U C T O R
*****************************/
void
ImageDoc_init(ImageDoc *img_doc)
{
    img_doc->prev = img_doc;
    img_doc->next = img_doc;
} /* ImageDoc_init */

ImageDoc *
ImageDoc_new(void)
{
    ImageDoc *img_doc = malloc(sizeof(ImageDoc));
    if (!img_doc) {
        ERR_OUT("Failed to allocate memory for ImageDoc!");
        return NULL;
    }

    ImageDoc_init(img_doc);

    return img_doc;
} /* ImageDoc_new */


/**************************
    D E S T R U C T O R
**************************/
ImageDoc *
ImageDoc_free(ImageDoc *img_doc)
{
    ImageDoc *result = (img_doc != img_doc->next) ? img_doc->next : NULL;

    free(img_doc);
    
    return result;
}


/********************
    M E T H O D S
********************/
/*    List Operations */
void
ImageDoc_add(ImageDoc *self, ImageDoc *new_img_doc)
{
    ImageDoc *prev = self->prev;

    self->prev        = new_img_doc;
    new_img_doc->next = self;

    prev->next        = new_img_doc;
    new_img_doc->prev = prev;
}

void
ImageDoc_remove(ImageDoc *self)
{
    ImageDoc *prev = self->prev;
    ImageDoc *next = self->next;
    
    prev->next = next;
    next->prev = prev;
}
