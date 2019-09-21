#include <stdio.h>
#include <stdlib.h>


/********************
���ң�
1. ��̬����
    ˳�����
    �۰���ң����ֲ��ң�
    �ֿ����
    ɢ�в���
2. ��̬���ң����޸Ĳ��ұ�
    �����������Ĳ���
    ɢ�в���
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
˳����ң����ҵ��򷵻ظ�Ԫ�ص�λ�ã����򷵻�-1��

ƽ�����ҳ��ȼ��㣺

�ɹ�ʱ��ASL = \sum_0^n{1/n * i} = (1 + n )/2
���ɹ�ʱ ASL = n+1

�˴���Ҫע��������˳����ң���ʧ�ܲ��ҳ��Ȳ�Ϊ n + 1
ASL = (1 + 2 + ... + n + n) / (n + 1) = n/2 + n/(n+1)
ʱ�临�Ӷ�Ϊ O(n)
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
�۰���ң������ֲ��ң��������������
�㷨˼�룺
ÿ�β���ֻ����������м俪ʼ��
��������м�Ԫ���򷵻�λ�ã�
���С�ڻ��ߴ����м�Ԫ�أ�
����Ҫ�������ǰ�벿�ֻ��ߺ�벿�����¿�ʼ

ƽ�����ҳ��ȷ�����
�����Ĺ��̹�����һ������������������ֵ���бȽϵĴ�������
�������ĸ߶ȣ��ڵȸ��ʵ�����£� ���ҳɹ��ĸ���Ϊ
ASL = {1/n * (1*1, 2*2 + ... + h * 2^(h-1))} = (n+1)/nlog2(n+1)-1

ʱ�临�Ӷ�Ϊ O(logn)

���ֲ��ҵĹ���ʵ���Ϲ�����һ���ж�����Ҳ��һ�ö���ƽ��������������������������������
���ĸ߶�Ϊ log2(N+1)����ȡ�����ʿ�֪���ڲ���ʧ�ܵ����������ڸ߶ȣ�
���ٴ������ڸ߶�-1
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
����򵥼�¼һ������һ�־�̬���ҷ�ʽ���ֿ����
�ֿ���Ҿ����ۺ��˶��ֲ��ң�˳����ҵ��ص㣬��Ԫ�طֿ���в��ҡ�
����Ԫ�ؿ������򵫿��Ԫ�ر�������
�������ǾͿ����ȶԿ���ж��ֲ��ң�Ȼ��Կ���Ԫ�ؽ���˳�����
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
