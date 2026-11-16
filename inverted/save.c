#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"inverted.h"

int save(mnode *arr[])
{
    
    if( empty_database(arr) == SUCCESS)
    {
        printf("ERROR: data base is empty saving is not possible\n");
    }


    char fname[30];

    printf("Enter the filename:");
    scanf("%s",fname);

    char *ext = strrchr(fname, '.');

        if (ext == NULL || strcmp(ext, ".txt") != 0)
        {
            printf("ERROR: %s is not a .txt file\n", fname);
            return FAILURE;
        }

        FILE *fp;
        fp = fopen(fname, "w");

        if(fp == NULL)
        {
            printf("error: file open failed in saving\n");
            return FAILURE;
        }

        int i;
        mnode *temp;
        for(i = 0; i < 26; i++)
        {
            //printf("entered the savedb\n");
            if(arr[i] != NULL)
            {
                temp = arr[i];

                
                while(temp)
                {

                    fprintf(fp,"#%d;%s;%d;",i,temp->word,temp->file_count);

                snode *stemp;
                stemp = temp->slink;

                    while(stemp)
                    {
                        fprintf(fp,"%s;%d;",stemp->file_name,stemp->word_count);
                        stemp = stemp->link;
                    }
                    fprintf(fp,"#\n");
                    temp = temp->mlink;
                }
            }     
        }

        fclose(fp);
 return SUCCESS;       

}