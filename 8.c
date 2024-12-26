#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int ssn;
    char name[20], department[20], designation[20], phone[20];
    float salary;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;
struct node *item;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("out of memory\n");
        exit(0);
    }
    return x;
}

void read() {
    item = getnode();
    printf("ssn:");
    scanf("%d", &item->ssn);
    printf("name:");
    scanf("%s", item->name);
    printf("department:");
    scanf("%s", item->department);
    printf("designation:");
    scanf("%s", item->designation);
    printf("salary:");
    scanf("%f", &item->salary);
    printf("phone:");
    scanf("%s", item->phone);
    item->llink = item->rlink = NULL;
}

NODE insert_front(NODE first) {
    read();
    if (first == NULL) return item;
    item->rlink = first;
    first->llink = item;
    return item;
}

NODE insert_rear(NODE first) {
    NODE cur;
    read();
    if (first == NULL) return item;
    cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = item;
    item->llink = cur;
    return first;
}

NODE delete_front(NODE first) {
    NODE second;
    if (first == NULL) {
        printf("employee list is empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("employee details deleted:ssn:=%d\n", first->ssn);
        free(first);
        return NULL;
    }
    second = first->rlink;
    second->llink = NULL;
    printf("employee details deleted:ssn:=%d\n", first->ssn);
    free(first);
    return second;
}

NODE delete_rear(NODE first) {
    NODE cur, prev;
    if (first == NULL) {
        printf("list is empty cannot delete\n");
        return first;
    }
    if (first->rlink == NULL) {
        printf("employee details deleted:ssn:=%d\n", first->ssn);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->rlink != NULL) {
        prev = cur;
        cur = cur->rlink;
    }
    printf("employee details deleted:ssn:=%d\n", cur->ssn);
    free(cur);
    prev->rlink = NULL;
    return first;
}

void display(NODE first) {
    NODE temp, cur;
    int count = 0;
    if (first == NULL) {
        printf("employee list is empty\n");
        return;
    }
    cur = first;
    while (cur != NULL) {
        printf("%d %f %s %s %s %s\n", cur->ssn, cur->salary, cur->name, cur->department, cur->designation, cur->phone);
        cur = cur->rlink;
        count++;
    }
    printf("number of employees=%d\n", count);
}

void main() {
    NODE first;
    int choice;
    first = NULL;
    for (;;) {
        printf("1:insert_front\n2:insert_rear\n");
        printf("3:delete_front\n4:delete_rear\n");
        printf("5:display\n6:exit\n");
        printf("enter the choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                first = insert_front(first);
                break;
            case 2:
                first = insert_rear(first);
                break;
            case 3:
                first = delete_front(first);
                break;
            case 4:
                first = delete_rear(first);
                break;
            case 5:
                display(first);
                break;
            default:
                exit(0);
        }
    }
}
