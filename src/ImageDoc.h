#ifndef IMAGEDOC_H
#define IMAGEDOC_H

#include "types.h"
#include "defs.h"

typedef struct ImageDoc ImageDoc;

enum {
    COLOR_FG = 0,
    COLOR_BG = 1
};

/* Constructors */
void      ImageDoc_init(ImageDoc *img_doc);
ImageDoc *ImageDoc_new(void);

/* Destructor */
ImageDoc *ImageDoc_free(ImageDoc *img_doc);

/* Methods */
/*    Add */
void      ImageDoc_add(ImageDoc *img_doc, ImageDoc *new_img_doc);
/*    Remove */
void      ImageDoc_remove(ImageDoc *img_doc);
/*    Getters */
Image    *ImageDoc_get_image(ImageDoc *img_doc);

void      ImageDoc_load(const char *path);


#endif /* IMAGEDOC_H */
