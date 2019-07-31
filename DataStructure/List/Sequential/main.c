#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Position;
typedef struct LNode *List;

#define MAXSIZE 100

struct LNode{
    int Data[MAXSIZE];
    Position last;
};

List InitialList(){
    List L;
    L = (List) malloc(sizeof(List));
    L->last = -1;
    return L;
}

bool judgeEmpty(List L){
    if (L->last == -1) return true;
    else return false;
}

bool insert(List L, int element, int position){
    if (position < 0){
        printf("Error：插入的位置小于0\n");
        return false;
    }
    if (position >= MAXSIZE){
        printf("Error: 插入的位置超出最大长度\n");
        return false;
    }
    if (L->last >= MAXSIZE - 1){
        printf("Error：表已经满了,无法继续插入.\n");
    }
    for (int i = L->last; i >= position; i--){
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[position] = element;
    L->last++;
    return true;
}

Position find(List L, int element){
    int i = 0;
    while(L->Data[i] != element && i <= L->last)
        i++;
    if (i == L->last) return -1;
    else return i;

}

bool deleteByIndex(List L, int index){
    if (L->last == -1){
        printf("The list is empty!\n");
        return false;
    }
    if (index < 0 || index > L->last){
        printf("Index is valid\n");
        return false;
    }
    for(int i = index; i < L->last + 1; i++){
        L->Data[i] = L->Data[i+1];
    }
    L->last--;
    return true;
}

bool deleteByElement(List L, int element){
    if (L->last == -1){
        printf("The list is empty!\n");
        return false;
    }
    int index = find(L, element);
    return deleteByIndex(L, index);
}

void printList(List L){
    if (L->last == -1){
        printf("The List is empty!\n");
        return;
    }
    int length = L->last + 1;
    for (int i = 0; i < length; i++){
        printf("%d \t", L->Data[i]);
    }
    printf("\n");
}

bool reverse(List L){
    if (L->last == -1){
        printf("The list is empty\n");
        return false;
    }
    for (int i = 0; i < (L->last + 1)/2; i++){
        int temp = L->Data[i];
        L->Data[i] = L->Data[L->last - i];
        L->Data[L->last - i] = temp;
    }
    return true;
}

bool reversePart(List L, int from, int to){
    if(L->last == -1){
        printf("The list is empty.\n");
        return false;
    }
    if(from > to){
        printf("ERROR: arg: from > to\n");
        return false;
    }
    if((from < 0 || to < 0) && (from > L->last || to > L->last)){
        printf("The from or to is out of array bound\n");
        return false;
    }
    for (int i = 0; i < (to - from + 1) / 2; i++){
        int temp = L->Data[from + i];
        L->Data[from + i] = L->Data[to - i];
        L->Data[to-i] = temp;
    }
    return true;
}

bool leftShift(List L, int leftStep){
    if (leftStep < 0 || leftStep > L->last + 1){
        printf("The left steps is not valid.\n");
        return false;
    }
    reversePart(L, 0, leftStep-1);
    reversePart(L, leftStep, L->last);
    reversePart(L, 0, L->last);
    return true;
}


int main()
{
    List L = InitialList();
    insert(L, 2, 0);
    printList(L);
    insert(L, 3, 1);
    insert(L, 4, 1);
    printList(L);
    reverse(L);
    printList(L);
    reversePart(L, 1, 2);
    printList(L);
    leftShift(L, 1);
    printList(L);
    printf("%d", 3/2);
    return 0;
}
