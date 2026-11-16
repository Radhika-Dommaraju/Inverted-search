#include"inverted.h"

int insertlast(Slist **head, Slist *new)
{
        if (*head == NULL)
        {
            *head = new;
        }
        else
        {
            Slist *temp = *head;

            while (temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = new;
        }

        return SUCCESS;
    }