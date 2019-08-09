#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 200

typedef struct SNode* Stack;
typedef struct SNode SNode;
struct SNode{
    int data[MAXSIZE];
    int top;
};

Stack initial_stack(){
    Stack s = (Stack)malloc(sizeof(SNode));
    s->top = -1;
}

bool push(Stack S, int item){
    if(S->top == MAXSIZE - 1){
        printf("ERROR: The stack is full!\n");
        return false;
    }
    else{
        S->top++;
        S->data[S->top] = item;
        return true;
    }
}

bool isEmpty(Stack s){
    return s == NULL || s->top == -1;
}

bool isFull(Stack s){
    return s->top == MAXSIZE - 1;
}

int getElement(Stack s, int index){
    if(s->top == -1){
        printf("The stack is empty!");
        return -1;
    }
    if(index > s->top || index < 0){
        printf("The index is out of bound!");
        return -1;
    }

    return s->data[index];
}

int pop(Stack S){
    if(isEmpty(S))
        return -1;
    return S->data[(S->top)--];
}

int top(Stack S){
    if(isEmpty(S))
        return -1;
    return S->data[S->top];
}

void printStack(Stack S){
    if(isEmpty(S))
        return;

    for(int i = 0; i <= S->top; i++){
        printf("%d \t", S->data[i]);
    }
    printf("\n");
}

int main()
{
    Stack s = initial_stack();
    push(s, 3);
    push(s, 5);
    pop(s);
    printStack(s);
}
