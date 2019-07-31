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
    // ͷ�巨������������
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->data = data;
    head->next = NULL;
    if(L == NULL){
        // ͷ�ڵ�������
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
    ����һ�������һ�����ָ�룬Ҫ���������ɾ���ý��ָ�룬����һ����������
    1. ��ͷ������ֱ����λ����Ŀ��ָ�룬ʱ�临�Ӷ�Ϊ O��n��
    2. ֱ��ɾ��Ŀ����ĺ�̽�㣬������̽���ֵ���������㣬ʱ�临�Ӷ�ΪO(1);
    ������õڶ��ַ���
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
    printf("��ʼ����\n");
    printList(L);
    insert_head(L, 3);
    insert_head(L, 4);
    insert_head(L, 5);
    printf("ͷ������ 3�� 4��5\n");
    printList(L);
    insert_end(L, 1);
    insert_end(L, 2);
    printf("β������ 1�� 2\n");
    printList(L);
    insert(L, 2, 100);
    printf("index %d λ�ò��� %d\n", 2, 100); //TOFIX
    printList(L);
    LinkList p = findDataByIndex(L,0);
    printf("index Ϊ 0��λ��ֵΪ %d\n",  p->data);
    p = findDataByVal(L, 100); // TOFIX
    printf("data Ϊ 100 ��λ��ֵΪ %d\n", p->data);
    deleteByIndex(L, 2);
    printf("ɾ��λ��Ϊ2����ֵ\n");
    printList(L);

}
