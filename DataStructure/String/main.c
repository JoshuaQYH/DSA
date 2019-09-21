#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXLEN 255

// ����˳���ʾ
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;

// �ѷ���洢��ʾ
typedef struct{
    char* ch;
    int length;
}HString;

void assignStr(HString *str, char *arr, int length){
    //  �ȿ���һ��ռ䣬���ڴ洢�ַ������Ԫ��
    char *ch = (char*)malloc(sizeof(char) * length);
    char *start = ch;
    for(int i = 0; i < length; i++){
        // ���ַ����ݿ�������Ӧ��ַ������
        *ch++ = *arr++;   // ���û��ʵ�ֿ��ٿռ䣬��ô���������״̬����
    }
    str->length = length;
    // �����ٵĿռ���׵�ַ��ֵ���ַ���ָ��
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
