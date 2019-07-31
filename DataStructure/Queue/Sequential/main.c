#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 200
#define ERROR -1

typedef struct QNode* Queue;
typedef struct QNode QNode;

struct QNode{
    int data[MAXSIZE];
    int rear;  // rear所在位置就是刚入队元素的位置
    int front; // front的位置表示队头
    // 当 rear + 1 % MAXSIZE == front时，队满;
    // 当 rear == front 时，队空
    // 当删除时，front 向前移动一个位置；
    // 当处于边界的时候，可以考虑 + 1 % maxsize 实现循环移动指针的效果。
};

Queue initialQueue(){
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->rear=Q->front=0;
    return Q;
}

bool addQ(Queue Q,int item){
    /*添加元素的方法是：先移动rear指针，然后在rear所指的位置记录数据*/
    if(Q->rear + 1 % MAXSIZE == Q->front){
        printf("The queue is full \n");
        return false;
    }
    Q->rear = (Q->rear + 1)% MAXSIZE;
    Q->data[Q->rear] = item;
    return true;
}

int deleteQ(Queue Q){
    if(Q->front == Q->rear){
        printf("The queue is empty \n");
        return ERROR;
    }
    Q->front = (Q->front + 1)  % MAXSIZE;
    return Q->data[Q->front];
}

void printQueue(Queue Q){
    if(Q->front == Q->rear)
        printf("\n");

    int front = Q->front;
    int rear = Q->rear;
    while(front != rear){
        printf("%d -> ", Q->data[front + 1]);
        front = (front + 1) % MAXSIZE;
    }
    printf("\n");
}

int main()
{
    Queue Q = initialQueue();
    addQ(Q, 1);
    addQ(Q, 2);
    addQ(Q, 3);
    printQueue(Q);
    deleteQ(Q);
    deleteQ(Q);
    printQueue(Q);
    return 0;
}
