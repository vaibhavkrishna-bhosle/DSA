//single linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    int usn;
    char name[20];
    char branch[20];
    int sem;
    int phno;
    struct node *next;
} node;

node *head = NULL;

void rear_insert()
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the USN: ");
    scanf("%d", &temp->usn);
    printf("Enter the Name: ");
    scanf("%s", temp->name);
    printf("Enter the Branch: ");
    scanf("%s", temp->branch);
    printf("Enter the Semester: ");
    scanf("%d", &temp->sem);
    printf("Enter the Phone Number: ");
    scanf("%d", &temp->phno);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void front_insert()
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the USN: ");
    scanf("%d", &temp->usn);
    printf("Enter the Name: ");
    scanf("%s", temp->name);
    printf("Enter the Branch: ");
    scanf("%s", temp->branch);
    printf("Enter the Semester: ");
    scanf("%d", &temp->sem);
    printf("Enter the Phone Number: ");
    scanf("%d", &temp->phno);
    temp->next = head;
    head = temp;
}

void display()
{
    node *p = head;
    if (p == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (p != NULL)
        {
            printf("USN: %d\n", p->usn);
            printf("Name: %s\n", p->name);
            printf("Branch: %s\n", p->branch);
            printf("Semester: %d\n", p->sem);
            printf("Phone Number: %d\n", p->phno);
            p = p->next;
        }
    }
}

void delete_front(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        node *temp=head;
        head=head->next;
        free(temp);
    }
}

void delete_rear(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        node *p=head;
        node *q=NULL;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        q->next=NULL;
        free(p);
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("----------------------------------------------------\n");
        printf("Menu\n");
        printf("1. Insert at rear\n");
        printf("2. Insert at front\n");
        printf("3. Display\n");
        printf("4. Delete at front\n");
        printf("5. Delete at rear\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            rear_insert();
            break;
        case 2:
            front_insert();
            break;
        case 3:
            display();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_rear();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}