#include<stdlib.h>
#include<string.h>
#include "inverted.h"

snode *create_sub_node(char *filename)
{
    snode *new;
    new = malloc(sizeof(snode));
    strcpy(new->file_name, filename);
    new->word_count = 1;
    new->link = NULL;

    return new;
}