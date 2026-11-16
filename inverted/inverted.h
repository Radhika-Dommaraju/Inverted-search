#ifndef INVERTED_H
#define INVERTED_H


#include<stddef.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define LIST_EMPTY -3
#define SUCCESS 0
#define FAILURE -1
#define WORD_NOT_FOUND -2


typedef struct main_node
{
    char word[20];
    int file_count;
    struct main_node *mlink;
    struct sub_node *slink;
}mnode;

typedef struct sub_node
{
    int word_count;
    char file_name[30];
    struct sub_node *link;
}snode;

typedef struct linklist
{
    char data[20];
    struct linklist *link;

}Slist;

#endif 

int read_and_validate(char *argv[], Slist **head);
int insertlast(Slist **head, Slist *new);

//to create  main node
mnode *create_main_node(char word[]);

//to create a sub node
snode *create_sub_node(char *filename);

//create a data base
int create_database(Slist **head, mnode *arr[]);

//display data base
int display_db(mnode *arr[]);

//search word
int search(mnode *arr[]);

//save data base
int save(mnode *arr[]);

//update data base
int update_data_base(mnode *arr[], Slist **head);

//validate backup
int validate_backup(char backup[],mnode *arr[]);

//check if database is empty or not
int empty_database(mnode *arr[]);

//delete the file name 
int delete_element(Slist **head, char data[]);

