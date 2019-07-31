#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 200
#define ERROR -1

typedef struct QNode* Queue;
typedef struct QNode QNode;

struct QNode{
    int data[MAXSIZE];
    int rear;  // rear����λ�þ��Ǹ����Ԫ�ص�λ��
    int front; // front��λ�ñ�ʾ��ͷ
    // �� rear + 1 % MAXSIZE == frontʱ������;
    // �� rear == front ʱ���ӿ�
    // ��ɾ��ʱ��front ��ǰ�ƶ�һ��λ�ã�
    // �����ڱ߽��ʱ�򣬿��Կ��� + 1 % maxsize ʵ��ѭ���ƶ�ָ���Ч����
};

Queue initialQueue(){
    Queue Q = (Queue)malloc(sizeof(QNode));
    Q->rear=Q->front=0;
    return Q;
}

bool addQ(Queue Q,int item){
    /*���Ԫ�صķ����ǣ����ƶ�rearָ�룬Ȼ����rear��ָ��λ�ü�¼����*/
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
