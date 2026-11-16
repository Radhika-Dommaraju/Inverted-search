#include<stdlib.h>
#include<string.h>
#include "inverted.h"



mnode *create_main_node(char word[])
{
    mnode *new;
    new = malloc(sizeof(mnode));
    strcpy(new->word, word);
    new->file_count = 1;
    new->mlink = NULL;
    new->slink = NULL;

    return new;
}