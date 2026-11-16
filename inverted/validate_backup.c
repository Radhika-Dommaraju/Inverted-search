#include"inverted.h"



int validate_backup(char backup[], mnode *arr[])
{
    int i;

    /* Database must be empty */
    for(i = 0; i < 26; i++)
    {
        if(arr[i] != NULL)
        {
            printf("error : data base is not empty, updating is not possible\n");
            return FAILURE;
        }
    }

    /* Check extension */
    char *ext = strrchr(backup, '.');

    if(ext == NULL || strcmp(ext, ".txt") != 0)
    {
        printf("ERROR: %s is not a .txt file\n", backup);
        return FAILURE;
    }

    FILE *fp = fopen(backup, "r");

    if(fp == NULL)
    {
        printf("Error : no such file exists\n");
        return FAILURE;
    }

    /* First character must be # */
    if(fgetc(fp) != '#')
    {
        fclose(fp);
        return FAILURE;
    }

    /* Go to end and find last non-whitespace character */
    fseek(fp, -1, SEEK_END);

    int ch;

    while((ch = fgetc(fp)) == '\n' || ch == '\r' || ch == ' ')
    {
        fseek(fp, -2, SEEK_CUR);
    }

    if(ch != '#')
    {
        fclose(fp);
        return FAILURE;
    }

    fclose(fp);

    return SUCCESS;
}