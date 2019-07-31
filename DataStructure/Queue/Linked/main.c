#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef struct QNode QNode;

struct QNode{
    int val;
    QNode* next;
};

struct LinkQueue{
    QNode *rear;  // 队头结点
    QNode *front; // 队尾结点
};

typedef struct LinkQueue *Queue;
typedef struct LinkQueue LinkQueue;

Queue initialQueue(){
    Queue Q = (Queue)malloc(sizeof(LinkQueue));
    Q->rear = NULL;
    Q->front = (QNode*)malloc(sizeof(QNode));
    Q->front->val=-1;  // make no sense.
    Q->front->next=Q->rear;
    return Q;
}

int AddQ(Queue Q, int val){
    QNode* qnode = (QNode*)malloc(sizeof(QNode));
    qnode->val = val;
    qnode->next=NULL;
    if(Q->rear == NULL){
        Q->rear = qnode;
        Q->front->next=qnode;
    }
    else{
        // printf("%d", Q->front->next->val);
        Q->rear->next = qnode;
        Q->rear = Q->rear->next;
    }
}


int deleteQ(Queue Q){
    if(Q->front->next == NULL){
        printf("The queue is empty!\n");
        return ERROR;
    }
    int val = 0;
    QNode* node = Q->front->next;
    val = node->val;
    if(node == Q->rear){
        // 只剩下一个结点
        free(node);
        Q->rear = Q->front->next = NULL;
    }
    else{
        Q->front->next = node->next;
        free(node);
    }
    return val;
}

void printQueue(Queue Q){
    if(Q->front->next==NULL){
        printf("print: queue is empty.\n");
        return;
    }
    QNode* qnode = Q->front->next;
    while(qnode){
        printf("%d ->", qnode->val);
        qnode = qnode->next;
    }
    printf("\n");
}


int main()
{
    Queue Q = initialQueue();
    AddQ(Q, 1);
    AddQ(Q, 2);
    AddQ(Q, 4);
    AddQ(Q, 5);
    printQueue(Q);
    deleteQ(Q);
    deleteQ(Q);
    printQueue(Q);
    return 0;
}
