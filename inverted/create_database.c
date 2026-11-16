#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include "inverted.h"

int create_database(Slist **head, mnode *arr[])
{
    if( empty_database(arr) == FAILURE)
    {
        printf("ERROR: create data base is already done\n");
        return FAILURE;
    }
    Slist *fname;
    fname = *head;
    FILE *fp;
    char word[20];
    int index;

    while(fname) // until last node of single linkedlist
    {
        fp = fopen(fname->data, "r");

        if(fp == NULL)
        {
            printf("ERROR");
            return FAILURE;
        }

        while(fscanf(fp, "%19s", word) == 1) //until EOF
        {
            if(!isalpha(word[0])) 
            continue;
            index = tolower(word[0]) - 'a';

            

            if(arr[index] == NULL) //if index has null create main and subnodes and update
            {
                mnode *mnew = create_main_node(word);
                if(mnew == NULL)
                return FAILURE;

                mnew->slink = create_sub_node(fname->data);

                arr[index] = mnew;
            }
            else  // if index not null
            {
                mnode *temp, *prev;
                temp = arr[index];
                prev = NULL;

                while(temp)
                {
                    if(strcmp(temp->word , word) == 0)
                    {
                        break;
                    }
                    else
                    {
                        prev = temp;
                        temp = temp->mlink;
                    }
                }

                if(temp == NULL) // word not existing
                {
                    mnode *mnew = create_main_node(word);
                    if(mnew == NULL)
                    {
                        return FAILURE;
                    }

                    mnew->slink = create_sub_node(fname->data);

                    prev->mlink = mnew;
                }
                else  // word exists
                {
                    snode *sprev, *stemp;
                    sprev = temp->slink;
                    stemp = temp->slink;

                    while(stemp)
                    {
                        if(strcmp(stemp->file_name, fname->data) == 0) // file name matched
                        {
                            stemp->word_count = (stemp->word_count) + 1;
                            break;

                        }
                        else
                        {
                            sprev = stemp;
                            stemp = stemp->link;
                        }
                    }
                    if(stemp == NULL) // file name not matched
                    {
                        snode *snew;
                        snew = malloc(sizeof(snode));
                        if(snew == NULL)
                        {
                            fclose(fp);
                            return FAILURE;
                        }

                        snew->word_count = 1;
                        strcpy(snew->file_name, fname->data);
                        snew->link = NULL;

                        sprev->link = snew;

                        temp->file_count = (temp->file_count) + 1;
                    }
                }
            }
        }
        fclose(fp);
        fname = fname->link;
    }
    return SUCCESS;
}