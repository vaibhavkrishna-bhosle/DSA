//circular queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1,count=0;

void insert(){
    int data;
    if(count==MAX){
        printf("----------------------------------Queue is full\n");
    }else{
        printf("Enter data: ");
        scanf("%d", &data);
        if(front == -1){
            front = 0;
        }
        rear = (rear+1)%MAX;
        queue[rear] = data;
        count++;
    }
}

void delete(){
    if(count==0){
        printf("----------------------------------Queue is empty\n");
    }else{
        printf("----------------------------------Deleted element is %d\n", queue[front]);
        front = (front+1)%MAX;
        count--;
    }
}

void display(){
    if(count==0){
        printf("----------------------------------Queue is empty\n");
    }else{
        for(int i = front; i != rear; i=(i+1)%MAX){
            printf("%d", queue[i]);
        }
        printf("%d", queue[rear]);
    }
}

int main(){
    int ch;
    while(1){
        printf("\n----------------------------------\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insert(); 
                    break;
            case 2: delete(); 
                    break;
            case 3: display(); 
                    break;
            case 4: exit(0);
        }
    }
    return 0;
}