#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


/************************
��������ģʽƥ���㷨��������
Ŀ�괮 ����Ϊ n
ģʽ�� ����Ϊ m

����һ��
������Ŀ�괮��״Ϊ a^n-1 X ģʽ��Ϊ b^-1 Y
�ܵıȽϴ���Ϊm(n - m + 1)
ʱ�临�Ӷ�ΪO(mn)

��������
- ��һ��λ�þ�ƥ��ɹ�
�Ƚϴ���Ϊm
ʱ�临�Ӷ�ΪO(m)
- ģʽ����һ���ַ�����ƥ�䲻�ɹ�
�Ƚϴ���Ϊn
ʱ�临�Ӷ�ΪO(n)
************************/

int naiveMatching_1(string str1, string str2, int startIndex){
    // ����ƥ���㷨1
    // ��ͷ��ʼ��λ��ȡstr1���Ӵ�������ͬstr2��
    // ���бȽ�
    int lastIndex = str1.length() - str2.length();
    int len = str2.length();

    if(lastIndex < startIndex){
        return -1;
    }

    for(int g = startIndex; g <= lastIndex; g++){
        if(str2 == str1.substr(g, len)){
            return g;
        }
    }
    return -1;
}

int naiveMatching_2(string str1, string str2, int startIndex){
    int lastIndex = str1.length() - str2.length();
    if(startIndex > lastIndex) return -1;
    int i = startIndex, j = 0;
    while(i < str1.length() && j < str2.length()){
        if(str1[i] == str2[j]){
            i++;
            j++;
        }
        else{
            j = 0;
            i = i - j + 1;
        }
    }
    if(j >= str2.length())
        return i - j;
    return -1;
}

int naiveMatching_3(string str1, string str2, int startIndex){
    for(int g = startIndex; g <= str1.length()-str2.length(); g++){
        for(int j = 0; ((j < str2.length() && str1[g + j] == str2[j])); j++){
            if(j == str2.length()-1) return g;
        }
    }
    return -1;
}

/******************************************

// KMP �㷨��Ϊ�˽���ַ�������Ƚϵ�����
// ��һ��ƥ��ʧ��֮�����ǿ��Զ�ģʽ�һ� j - k λ��jΪģʽ���ĳ��ȣ�
// ��k��������ģʽ�������һ��ֵ��
// ����һ��k��ô���ģ����һ��ģʽ���ڽ���ƥ���ʱ��ǰmλƥ��ɹ��ˣ�����m+1λƥ��ʧ����
// ���ǾͿ���ǰmλ��һ��ģʽ�Ӵ�����β��ȡ����Ϊk���Ӵ���ʹ�������Ӵ���ȣ���k+1����β���Ӵ����ȣ�
// ���k��������Ҫ�ҵ�k

����ģʽ��(����Ϊm)���������� N���� m��������������ɣ�������ʾģʽP���ַ��ֲ�����
�����������Ҳ��Ϊnext���飬next�����Ԫ�ع��췽�����£�
next[0] = -1;
next[j] = max{ 0<k<j & P[0...k-1] == P[j-k, j-1] // ��jΪ�ضϵ㣬����ǰj-1���ַ����ҵ���β�䴮�k
next[k] = 0  // ǰk-1���ַ����ɵĴ���β������ƥ������

ʱ�临�Ӷ�ΪO(m+n)
*****************************************/

int* findNext(string P){
    int j, k;
    int m = P.length();
    assert(m > 0);
    int *next = new int[m];
    assert(next != 0);
    next[0] = -1;
    j = 0;
    k = -1;
    while(j < m - 1){
        while(k >= 0 && P[k] != P[j])
            k = next[k];
        j++;
        k++;
        next[j] = k;
    }
    return next;
}

int KMPMatching(string T, string P, int *N, int start){
    /*
    T: Ŀ�괮
    P��ģʽ��
    N��ģʽ������������ next����
    start����ʼƥ��λ��
    */
    int j = 0;
    int i = start;
    int tLen = T.size();
    int pLen = P.size();
    if(tLen - pLen < start) return -1;
    while(j < pLen && i < tLen){
        if(j == -1 || T[i] == P[j]){
            i++;
            j++;
        }
        else j = N[j];
    }
    if(j >= pLen) return i-pLen;
    return -1;
}


int main()
{
    string str1 = "Hello world!";
    string str2 = "wor";
    cout << naiveMatching_1(str1, str2, 0) << endl;
    cout << naiveMatching_2(str1, str2, 0) << endl;
    cout << naiveMatching_3(str1, str2, 0) << endl;
    cout << KMPMatching(str1, str2, findNext(str2), 0);
    return 0;
}
