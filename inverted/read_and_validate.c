#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"inverted.h"

int read_and_validate(char *argv[], Slist **head)
{
    int i;
    FILE *fp;
    Slist *temp;

    for (i = 1; argv[i] != NULL; i++)
    {
        /* Check .txt extension */
        char *ext = strrchr(argv[i], '.');

        if (ext == NULL || strcmp(ext, ".txt") != 0)
        {
            printf("ERROR: %s is not a .txt file\n", argv[i]);
            return FAILURE;
        }

        /* Check whether file exists */
        fp = fopen(argv[i], "r");

        if (fp == NULL)
        {
            printf("ERROR: File %s does not exist\n", argv[i]);
            return FAILURE;
        }

        /* Check whether file is empty */
        fseek(fp, 0, SEEK_END);

        if (ftell(fp) == 0)
        {
            printf("ERROR: File %s is empty\n", argv[i]);
            fclose(fp);
            return FAILURE;
        }

        fclose(fp);

        /* Check duplicate filename */
        temp = *head;

        while (temp != NULL)
        {
            if (strcmp(temp->data, argv[i]) == 0)
            {
                printf("ERROR: %s is already present\n", argv[i]);
                return FAILURE;
            }

            temp = temp->link;
        }

        /* Create node */
        Slist *new = malloc(sizeof(Slist));

        if (new == NULL)
        {
            return FAILURE;
        }

        strcpy(new->data, argv[i]);
        new->link = NULL;

        insertlast(head, new);
    }

    return SUCCESS;
}