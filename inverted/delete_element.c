#include"inverted.h"

int delete_element(Slist **head, char data[])
{
    if((*head) == NULL)
        return LIST_EMPTY;
   
   // if list has only one node
   if((*head)->data == data && (*head)->link == NULL)
   {
       free((*head));
       *head = NULL;
       return SUCCESS;
   }
   Slist *temp , *prev;
   
   //if data found at first node 
    if((*head)->data == data)
    {
        temp = *head;
        *head = (*head)->link;
        free(temp);
        return SUCCESS;
    }
    
    //if found at other than 1st node
    temp = (*head)->link;
    prev = *head;
    
    while(temp != NULL)
    {
        
        if(temp->data == data)
        {
            prev->link = temp->link;
            free(temp);
            return SUCCESS;
        }
        prev = temp;
        temp = temp->link;
    }
    

}