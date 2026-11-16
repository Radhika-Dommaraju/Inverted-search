#include"inverted.h"


int empty_database(mnode *arr[])
{
    int i,count = 0;
    for(i = 0; i < 26; i++)
    {
        if(arr[i] != NULL)
        {
            count++;
        }
    }
    if(count > 1)
    {
        //printf("error : data base is not empty, updating is not possible\n");
        return FAILURE;
    }
    else
     return SUCCESS;

}