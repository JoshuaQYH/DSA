#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


/************************
分析朴素模式匹配算法的最差情况
目标串 长度为 n
模式串 长度为 m

考虑一下
最坏情况：目标串形状为 a^n-1 X 模式串为 b^-1 Y
总的比较次数为m(n - m + 1)
时间复杂度为O(mn)

最佳情况：
- 第一个位置就匹配成功
比较次数为m
时间复杂度为O(m)
- 模式串第一个字符总是匹配不成功
比较次数为n
时间复杂度为O(n)
************************/

int naiveMatching_1(string str1, string str2, int startIndex){
    // 朴素匹配算法1
    // 从头开始按位获取str1的子串（长度同str2）
    // 进行比较
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

// KMP 算法是为了解决字符串冗余比较的问题
// 当一次匹配失败之后，我们可以对模式右滑 j - k 位。j为模式串的长度，
// 而k则依赖于模式串本身的一个值。
// 解释一下k怎么来的，如果一个模式串在进行匹配的时候，前m位匹配成功了，但第m+1位匹配失败了
// 我们就考虑前m位这一个模式子串，首尾各取长度为k的子串，使得两个子串相等，而k+1的首尾两子串不等，
// 这个k就是我们要找的k

考虑模式串(长度为m)的特征向量 N，由 m个特征数整数组成，用来表示模式P的字符分布特征
这个特征向量也称为next数组，next数组的元素构造方法如下：
next[0] = -1;
next[j] = max{ 0<k<j & P[0...k-1] == P[j-k, j-1] // 以j为截断点，考虑前j-1个字符，找到首尾配串最长k
next[k] = 0  // 前k-1个字符构成的串首尾不存在匹配的情况

时间复杂度为O(m+n)
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
    T: 目标串
    P：模式串
    N：模式串的特征向量 next数组
    start：初始匹配位置
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
