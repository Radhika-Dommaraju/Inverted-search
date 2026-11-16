#include<stdio.h>
#include"inverted.h"


int main(int argc, char *argv[])
{
    mnode *arr[26] = {NULL};
    Slist *head;
    head = NULL;
    int choice;
    if(argc == 1)
    {
        printf("ERROR : invalid input\n");
        return -1;
    }

    if (read_and_validate(argv, &head) == FAILURE)
    {
        printf("read and validate failed\n");
        return FAILURE;
    }
    else
    {
        printf("Read and validate sucess\n");
    }
    

    while(1)
    {
        printf("1.create\n2.Display\n3.Search\n4.Save\n5.Update\n6.Exit\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
             if(create_database(&head,arr) == FAILURE)
             {
                printf("ERROR: create data base failed\n");
             }
             else
             {
                printf("Created data base successfully\n");
             }
            break;
            case 2:
            if(display_db(arr) == FAILURE)
            {
                printf("error: display failed\n");
            } 
            else
            {
                printf("display successful\n");
            }
            break;

            case 3:
            int res = search(arr);
            if(res == FAILURE)
            {
                printf("Error searching failed\n");
            }
            else if (res == WORD_NOT_FOUND)
            {
                printf("Word not found\n");
            }
            else
            {
                printf("word found\n");
            }
            break;
            case 4:
            if(save(arr) == FAILURE)
            {
                printf("error:saving failed\n");

            }
            else
            {
                printf("saving data base is successful\n");
            }
            break;
            case 5:
            if(update_data_base(arr, &head) == FAILURE)
            {
                printf("Error: updation failed\n");    
            }
            else
            {
                printf("updated data base successfully\n");
            }
            break;

            case 6:
            return 0;
            break;

            default:
            printf("INvalid choice \n");
            break;


        }
    }

}