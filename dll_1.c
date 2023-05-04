#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct double_ll
{
    int data;
    struct double_ll *prev;
    struct double_ll *next;
}dll;

void insert_at_last(dll **head);
void insert_at_first(dll **head);
void delete_at_first(dll **head);
void delete_at_last(dll **head);
void display(dll **head);

int main()
{
    dll *head = NULL;
    int option;
    while(1)
    {
        printf("1. Insert at last\n2. Insert at first\n3. Delete at first\n4. Delete at last\n5. Display\n6. Exit\nEnter the option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: insert_at_last(&head);
                    break;
            case 2: insert_at_first(&head);
                    break;
            case 3: delete_at_first(&head);
                    break;
            case 4: delete_at_last(&head);
                    break;
            case 5: display(&head);
                    break;
            case 6: exit(1);
                    break;
        }
    }
}

void insert_at_last(dll **head)
{
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    dll *newnode = (dll *)malloc(sizeof(dll));
    if(newnode == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;
        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            dll *temp = *head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void insert_at_first(dll **head)
{
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    dll *newnode = (dll *)malloc(sizeof(dll));
    if(newnode == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;
        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            newnode->next = *head;
            (*head)->prev = newnode;
            *head = newnode;
        }
    }
}

void delete_at_last(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *temp = *head;
        dll *temp1 = NULL;
        while(temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}

void delete_at_first(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *temp = *head;
        dll *temp1 = (*head)->next;
        temp1->prev = NULL;
        printf("Deleted Item is %d\n", temp->data);
        free(temp);
        *head = temp1;
        
    }
}
void display(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *temp = *head;
        printf("List elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


