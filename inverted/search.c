#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include"inverted.h"


int search(mnode *arr[])
{
    
    if( empty_database(arr) == SUCCESS)
    {
        printf("ERROR:  data base is empty searching not possible\n");
        return FAILURE;
    }
    
    char word[20];
    printf("Enter the word to search:");
    scanf("%s", word);

    int index;
    index = (tolower(word[0])) - 'a';

    if(arr[index] == NULL) // if no word
    {
        return FAILURE;
    }
    else // if index not null
    {
        mnode *temp;
        temp = arr[index];
        while(temp)
        {

        if(strcmp(temp->word, word) == 0)
        {
            snode *stemp;
            stemp = temp->slink;

            printf("word %s is present in %d file(s)\n", temp->word, temp->file_count);

            while(stemp)
            {
                printf("%s->%d \n",stemp->file_name, stemp->word_count);
                stemp = stemp->link;
            }
            return SUCCESS;
        }
        else
        temp = temp->mlink;
       }

       if (temp == NULL)
       return WORD_NOT_FOUND;
    }

return SUCCESS;
}