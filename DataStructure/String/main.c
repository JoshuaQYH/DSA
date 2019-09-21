#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXLEN 255

// 定长顺序表示
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;

// 堆分配存储表示
typedef struct{
    char* ch;
    int length;
}HString;

void assignStr(HString *str, char *arr, int length){
    //  先开辟一块空间，用于存储字符数组的元素
    char *ch = (char*)malloc(sizeof(char) * length);
    char *start = ch;
    for(int i = 0; i < length; i++){
        // 将字符内容拷贝到对应地址的内容
        *ch++ = *arr++;   // 如果没有实现开辟空间，那么会出现死机状态。。
    }
    str->length = length;
    // 将开辟的空间的首地址赋值给字符串指针
    str->ch = start;
}

void copyStr(HString *str1, HString *str2){
    assignStr(str1, str2->ch, str2->length);
}

void concat(HString *str1, HString *str2){
    assert(str1 != NULL && str2 != NULL);
    int length = str1->length + str2->length;
    char *concatCh = (char*)malloc(sizeof(char)*length);
    char *ch = concatCh;
    char *ch1 = str1->ch;
    char *ch2 = str2->ch;
    for(int i = 0; i < str1->length + str2->length; i++){
        if(i < str1->length){
            *ch++ = *ch1++;
        }
        else{
            *ch++ =*ch2++;
        }
    }
    free(str1->ch);
    str1->ch = concatCh;
    str1->length += str2->length;
}


void printfStr(HString *str){
    char* tmpCh = str->ch;
    for(int i = 0; i < str->length; i++){
        printf("%c ", *tmpCh);
        tmpCh++;
    }
    printf("\n");
}

int main()
{
    char arr[5] = {'h','e','l','l','o'};
    HString* str = (HString*)malloc(sizeof(HString));
    assignStr(str, arr, sizeof(arr));
    printfStr(str);
    HString* str1 = (HString*)malloc(sizeof(HString));
    copyStr(str1, str);
    printfStr(str1);
    concat(str1, str);
    printfStr(str1);
    return 0;
}
