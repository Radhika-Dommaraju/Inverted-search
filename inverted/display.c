#include<stdio.h>
#include"inverted.h"


int display_db(mnode *arr[])
{
    
    if( empty_database(arr) == SUCCESS)
    {
        printf("ERROR: data base is empty display is not possible\n");
        return FAILURE;
    }


    int i;

    printf("Index    Word                 filecount    filename                 wordcount\n");

    for(i = 0; i < 26; i++)
    {
        if(arr[i] != NULL)
        {
            mnode *temp;
            temp = arr[i];

            while(temp)
            {
                printf("%-8d", i);
                printf("%-21s", temp->word);
                printf("%-13d", temp->file_count);

                snode *stemp;
                stemp = temp->slink;

                while(stemp)
                {
                    printf("%-25s", stemp->file_name);
                    printf("%-10d", stemp->word_count);

                    stemp = stemp->link;

                    printf("\n");
                    
                    /* For next file, leave first 3 columns empty */
                    if(stemp != NULL)
                    {
                        printf("%-8s%-21s%-13s", "", "", "");
                    }
                }

                temp = temp->mlink;
                printf("\n");
            }
        }
    }

    return SUCCESS;
}