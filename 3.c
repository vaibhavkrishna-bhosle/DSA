//STACK OPRATION
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX], top = -1;

void push(){
    int data;
    if(top == MAX-1){
        printf("----------------------------------Stack is full\n");
    }else{
        printf("Enter data: ");
        scanf("%d", &data);
        stack[++top] = data;
    }
}

void pop(){
    if(top == -1){
        printf("----------------------------------Stack is empty\n");
    }else{
        printf("----------------------------------Deleted element is %d\n", stack[top--]);
    }
}

void display(){
    if(top == -1){
        printf("----------------------------------Stack is empty\n");
    }else{
        for(int i = top; i >= 0; i--){
            printf("%d", stack[i]);
        }
    }
}

void palindrome(){
    int i, j;
    for(i = 0, j = top; i < j; i++, j--){
        if(stack[i] != stack[j]){
            printf("----------------------------------Not palindrome\n");
            return;
        }
    }
    printf("----------------------------------Palindrome\n");
}

int main(){
    int ch;
    while(1){
        printf("\n----------------------------------\n1. Push\n2. Pop\n3. Display\n4. Palindrome\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: push(); 
                    break;
            case 2: pop(); 
                    break;
            case 3: display(); 
                    break;
            case 4: palindrome(); 
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}