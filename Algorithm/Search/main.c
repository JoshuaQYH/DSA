#include <stdio.h>
#include <stdlib.h>


/********************
查找：
1. 静态查找
    顺序查找
    折半查找（二分查找）
    分块查找
    散列查找
2. 动态查找（会修改查找表）
    二叉排序树的查找
    散列查找
*********************/

typedef struct{
    int *data;
    int length;
}Table;

void init(Table *T, int *array, int length){
    if(length <= 0) return;
    int *val = array;
    int *tmpVal = val;
    for(int i = 0; i < length; i++){
        tmpVal = array;
        array++;
        tmpVal++;
    }
    T->data = val;
    T->length = length;
}

void printTable(Table* T){
    int i = 0;
    int *element = T->data;
    while(i < T->length){
        printf("%d ", *element);
        element++;
        i++;
    }
    printf("\n");
}

/*********************************************************
顺序查找，若找到则返回该元素的位置，否则返回-1；

平均查找长度计算：

成功时，ASL = \sum_0^n{1/n * i} = (1 + n )/2
不成功时 ASL = n+1

此处需要注意有序表的顺序查找，其失败查找长度不为 n + 1
ASL = (1 + 2 + ... + n + n) / (n + 1) = n/2 + n/(n+1)
时间复杂度为 O(n)
**********************************************************/
int seqSearch(Table* T, int target){
    int *data = T->data;
    for(int i = 0; i < T->length; i++){
        if(target == *data){
            return i;
        }
        data++;
    }
    return -1;
}

/**********************************************************
折半查找，即二分查找，仅适用于有序表
算法思想：
每次查找只能在数组的中间开始，
如果等于中间元素则返回位置，
如果小于或者大于中间元素，
则需要从数组的前半部分或者后半部分重新开始

平均查找长度分析：
搜索的过程构成了一个二叉搜索树，给定值进行比较的次数不会
超过树的高度，在等概率的情况下， 查找成功的概率为
ASL = {1/n * (1*1, 2*2 + ... + h * 2^(h-1))} = (n+1)/nlog2(n+1)-1

时间复杂度为 O(logn)

二分查找的过程实际上构成了一棵判定树，也是一棵二叉平衡树，二叉排序树（其中序序列有序）
树的高度为 log2(N+1)向上取整，故可知对于查找失败的最大次数等于高度，
最少次数等于高度-1
***********************************************************/
int binarySearch(int array[], int length, int target){
    int low=0, high=length-1, mid;
    while(low <= high){
        mid = (low + high) /2;
        if(array[mid] == target)
            return mid;
        if(target < array[mid])
            high = mid - 1;
        if(target > array[mid])
            low = mid + 1;
    }
    return -1;
}

/***************
这里简单记录一下另外一种静态查找方式，分块查找
分块查找就是综合了二分查找，顺序查找的特点，将元素分块进行查找。
块内元素可以无序但块间元素必须有序。
这样我们就可以先对块进行二分查找，然后对块内元素进行顺序查找
****************/

int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("The array length: %d\n", sizeof(array)/sizeof(int));
    Table *T = (Table*)malloc(sizeof(Table));
    init(T, array, sizeof(array)/sizeof(int));
    printTable(T);

    printf("-----sequence search----\n");
    printf("0 = %d \n", seqSearch(T, 1));
    printf("-1 = %d \n", seqSearch(T, 11));

    printf("-------binary search -----\n");
    printf("2 = %d \n", binarySearch(array, sizeof(array)/sizeof(int), 3));
    printf("9 = %d \n", binarySearch(array, sizeof(array)/sizeof(int), 10));

    return 0;
}
