#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SNode* Stack;
typedef struct SNode SNode;

struct SNode{
    int data;
    SNode* next;
};

Stack initial_stack(){
    Stack s = (Stack)malloc(sizeof(SNode));
    s->next=NULL;
    s->data=-1; // 无意义的空结点
    return s;
}

bool isEmpty(Stack s){
    return s->next == NULL;
}

bool push(Stack s, int item){
    if(s == NULL)
        return false;
    Stack tmpNode = (Stack)malloc(sizeof(SNode));
    tmpNode->data=item;
    tmpNode->next=s->next;
    s->next = tmpNode;
    return true;
}

int top(Stack s){
    if(isEmpty(s))
        return -1;
    return s->next->data;
}

int pop(Stack S){
    if(isEmpty(S))
        return -1;
    int topVal = top(S);
    Stack oldTopNode = S->next;
    Stack newTopNode = oldTopNode->next;
    S->next= newTopNode;
    free(oldTopNode);
    return topVal;
}

void printStack(Stack s){
    if(isEmpty(s))
        return;

    Stack node = s->next;

    while(s){
        printf("%d -> ",  s->data);
        s = s->next;
    }
    printf("\n");
}

int main()
{
    Stack s = initial_stack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printStack(s);
    pop(s);
    printStack(s);
    return 0;
}
