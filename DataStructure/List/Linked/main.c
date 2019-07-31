#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode* next;
} LNode;
typedef LNode* LinkList;


LinkList initial(int initialVal){
    LinkList s1 = (LinkList)malloc(sizeof(LNode));
    s1->next=NULL;
    LinkList s2 = (LinkList)malloc(sizeof(LNode));
    s2->next=NULL;
    s2->data=initialVal;
    s1->next=s2;
    return s1;
}

int getListLength(LinkList L){
    if(L == NULL){
        return 0;
    }
    LinkList p = L->next;
    int len = 0;
    while(p != NULL){
        p = p->next;
        len ++;
    }
    return len;
}

LinkList insert_head(LinkList L, int data){
    // 头插法，逆向建立链表
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->data = data;
    head->next = NULL;
    if(L == NULL){
        // 头节点无意义
        L = (LinkList)malloc(sizeof(LNode));
        L->next = head;
        return L;
    }
    else{
        head->next = L->next;
        L->next = head;
        return L;
    }
}

LinkList insert_end(LinkList L, int data){
    LinkList tail = (LinkList)malloc(sizeof(LNode));
    tail->data = data;
    tail->next = NULL;
    LinkList s = L;
    while(s != NULL){
        if(s->next == NULL){
            s->next = tail;
            break;
        }
        // printf("%d", s->next->data);
        s = s->next;
    }
    return L;
}

LinkList insert(LinkList L, int index, int data){
    int len = getListLength(L);
    if(index > len || index < 0){
        printf("ERROR: the index is out of bound");
        return NULL;
    }
    if(index == 0){
        return insert_head(L, data);
    }
    if(index == len){
        return insert_end(L, data);
    }
    LinkList p = L->next;

    int count = 0;
    while(1){
        if(count == index - 1){
            LinkList pnext = p->next;
            LinkList newNode = (LinkList)malloc(sizeof(LNode));
            newNode->data=data;
            newNode->next = pnext;
            p->next=newNode;

            return L;
        }
        count++;
        p = p->next;
    }
    return L;
}

LinkList findDataByVal(LinkList L, int data){
    LinkList s = L->next;
    while(s != NULL){
        if(s->data == data){
            return s;
        }
        s = s->next;
    }
    return NULL;
}

LinkList findDataByIndex(LinkList L, int index){
    if(index < 0){
        printf("ERROR: index is lower than 0.");
        return NULL;
    }

    LinkList p = L->next;
    int couter = 0;
    while(p != NULL){
        if(couter == index){
            return p;
        }
        couter++;
        p = p->next;
    }
    return NULL;
}

LinkList deleteByPtr(LinkList target){
    /*
    给定一个链表和一个结点指针，要求从链表中删除该结点指针，做法一般有两个：
    1. 从头遍历，直到定位到该目标指针，时间复杂度为 O（n）
    2. 直接删除目标结点的后继结点，并将后继结点的值赋给自身结点，时间复杂度为O(1);
    这里采用第二种方法
    */
    if(target->next == NULL){
        target=NULL;
    }
    else{
        LinkList p = target->next;
        target->next = p->next;
        target->data = p->data;
        free(p);
    }
    return target;
}


LinkList  deleteByIndex(LinkList L, int index){
    LinkList target = findDataByIndex(L, index);
    return target == NULL ? L : deleteByPtr(target);
}


void printList(LinkList L){
    LinkList p = L->next;
    while(p != NULL){
        printf("%d \t", p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    LinkList L = initial(0);
    printf("初始化：\n");
    printList(L);
    insert_head(L, 3);
    insert_head(L, 4);
    insert_head(L, 5);
    printf("头部插入 3， 4，5\n");
    printList(L);
    insert_end(L, 1);
    insert_end(L, 2);
    printf("尾部插入 1， 2\n");
    printList(L);
    insert(L, 2, 100);
    printf("index %d 位置插入 %d\n", 2, 100); //TOFIX
    printList(L);
    LinkList p = findDataByIndex(L,0);
    printf("index 为 0的位置值为 %d\n",  p->data);
    p = findDataByVal(L, 100); // TOFIX
    printf("data 为 100 的位置值为 %d\n", p->data);
    deleteByIndex(L, 2);
    printf("删除位置为2的数值\n");
    printList(L);

}
