#include"inverted.h"

int update_data_base(mnode *arr[], Slist **head)
{
    char backup[30];

    printf("Enter the saved file name to update the data base:");
    scanf("%29s", backup);

    /* Validate backup file */
    if(validate_backup(backup, arr) == FAILURE)
    {
        printf("error: validation failed\n");
        return FAILURE;
    }

    FILE *fp = fopen(backup, "r");

    if(fp == NULL)
    {
        printf("Error: file does not exist\n");
        return FAILURE;
    }

    char line[200];

    while(fscanf(fp, "%199s", line) == 1)
    {
        /* Get index */
        char *tok = strtok(line, "#;");

        if(tok == NULL)
        {
            fclose(fp);
            return FAILURE;
        }

        int ind = atoi(tok);

        if(ind < 0 || ind > 25)
        {
            fclose(fp);
            return FAILURE;
        }

        /* Get word */
        tok = strtok(NULL, "#;");

        if(tok == NULL)
        {
            fclose(fp);
            return FAILURE;
        }

        mnode *mnew = create_main_node(tok);

        if(mnew == NULL)
        {
            fclose(fp);
            return FAILURE;
        }

        /* Get file count */
        tok = strtok(NULL, "#;");

        if(tok == NULL)
        {
            fclose(fp);
            return FAILURE;
        }

        int fc = atoi(tok);

        mnew->file_count = fc;

        /* Insert main node */
        if(arr[ind] == NULL)
        {
            arr[ind] = mnew;
        }
        else
        {
            mnode *temp = arr[ind];

            while(temp->mlink != NULL)
            {
                temp = temp->mlink;
            }

            temp->mlink = mnew;
        }

        /* Read files */
        int i;

        for(i = 0; i < fc; i++)
        {
            /* Get file name */
            tok = strtok(NULL, "#;");

            if(tok == NULL)
            {
                fclose(fp);
                return FAILURE;
            }

            char filename[20];
            strcpy(filename, tok);

            /* Get word count */
            tok = strtok(NULL, "#;");

            if(tok == NULL)
            {
                fclose(fp);
                return FAILURE;
            }

            int wc = atoi(tok);

            /* Create sub node */
            snode *snew = create_sub_node(filename);

            if(snew == NULL)
            {
                fclose(fp);
                return FAILURE;
            }

            snew->word_count = wc;

            /* Insert sub node */
            if(mnew->slink == NULL)
            {
                mnew->slink = snew;
            }
            else
            {
                snode *stemp = mnew->slink;

                while(stemp->link != NULL)
                {
                    stemp = stemp->link;
                }

                stemp->link = snew;
            }

            /*
             * Add filename to Slist only if it
             * does not already exist.
             */
            Slist *temp = *head;
            int found = 0;

            while(temp != NULL)
            {
                if(strcmp(temp->data, filename) == 0)
                {
                    found = 1;
                    break;
                }

                temp = temp->link;
            }

            if(found == 0)
            {
                Slist *new = malloc(sizeof(Slist));

                if(new == NULL)
                {
                    fclose(fp);
                    return FAILURE;
                }

                strcpy(new->data, filename);
                new->link = NULL;

                insertlast(head, new);
            }
        }
    }

    fclose(fp);

    //printf("Database updated successfully\n");

    return SUCCESS;
}