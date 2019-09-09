#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100  // ���Ķ�����
typedef char VertexType  // �����������
typedef int EdgeType     // ��Ȩֵ����������

/********************
ͼ�Ĵ洢��ʾ
1. ��ͨ�ڽӾ����ʾ��
2. ��ͨ�ڽӱ��ʾ��
3. ʮ���ڽӱ�����ͼ��
4. �������ӱ�����ͼ��
*********************/
// �ڽӾ����ʾ��
typedef struct{
    VertexType Vex[MaxVertexNum];  //�����
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //�߱�
    int vexNum, arcNum;   // ͼ��ǰ�Ķ������ͻ���
}MGraph;

// ���ʹ��һά�������洢**����ͼ**����ô����һ������Gij,�������ж�Ӧ���±�Ϊ
// (i * (i + 1) / 2  + j )

// �ڽӱ��ʾ��
typedef struct ArcNode{
    int adjVex;            // �û�ָ��Ķ���
    struct ArcNode* next;  // ָ����һ����
    int edgeVal;           // �����Ȩֵ
}ArcNode;

typedef struct VNode{
    VertextType data;       // ����
    ArcNode* first;         // ָ���һ�������ö����ָ��
}VNode;

typedef struct{
    VNode nodeList[MaxVertexNum]; // �����
    int vexNum, arcNum;            // �����ͻ���
}ALGraph;

//  ��Ҫע����ǣ����ǹ涨���������Ԫ�ؼ���ģ�����������Ԫ�ؼ���ġ�


// ʮ�������ʾ�����������ͼ��
// ���ڽӱ�Ļ����Ϸ�չ����
typedef struct T_ArcNode{    // �߱���
    int headVex, tailVex;  // �û�ָ���ͷ���㣬β����
    ArcNode *hLink, tLink; // ָ��ͷ��ͬ (->A) �ͻ�β��ͬ (A->) �Ľ��
    int edgeVal;           // �����Ȩֵ
}T_ArcNode;

typedef struct T_VNode{
    VertextType data;       // �������
    ArcNode *firstIn, *firstOut;  // ָ���һ����Ȼ��ͳ��Ȼ�
}T_VNode;

typedef struct{
    T_VNode nodeList[MaxVertexNum]; // �����
    int vexNum, arcNum;            // �����ͻ���
}T_Graph;


// �ڽӶ��ر��������ͼ��
// ��ͨ�ڽӱ���ȷ����������֮���Ƿ���ڱߣ���Ҫ������Ч�ʵͣ�
typedef struct M_ArcNode{
    bool mark;              // �����������
    int iVex, jVex;         // ָʾ���������λ��
    struct L_ArcNode *iLink, *jLink;  // ָʾ�����������һ����
}M_ArcNode;

typedef struct L_VNode{
    VertexType data;   // ������Ϣ
    L_ArcNode* first;  // ��������ĵ�һ����
}M_VNode;

typedef struct{
    L_VNode nodeList[MaxVertexNum]; // �ڽӱ�
    int vexNum, arcNum;             // ͼ�Ķ������л���
}M_Graph;


/*********************************
ͼ�Ļ�������
1. �ж�ͼ�Ƿ���� x - y �ı�
2. �г��붥��x�ڽӵı�
3. ��ͼ�в��붥��
4. ��ͼ��ɾ������
5. ��ͼ�в����
6. ��ͼ��ɾ����
7. ���ض���ĵ�һ���ڽӵ�
8. ��ȡ�߶�Ӧ��Ȩֵ
9. ���ñ߶�Ӧ��Ȩֵ
**********************************/
/*
typedef struct ArcNode{
    int adjVex;            // �û�ָ��Ķ���
    struct ArcNode* next;  // ָ����һ����
    int edgeVal;           // �����Ȩֵ
}ArcNode;

typedef struct VNode{
    VertextType data;       // ����
    ArcNode* first;         // ָ���һ�������ö����ָ��
}VNode;

typedef struct{
    VNode nodeList[MaxVertexNum]; // �����
    int vexNum, arcNum;            // �����ͻ���
}ALGraph;

����ͨ�ڽӱ�Ϊ����ʵ������ͼ�Ĳ���ɾ�����㣬����ɾ����
*/

void initGraph(){

}

void addVertex(){

}

void deleteVertex(){

}

void addEdge(){

}

void deleteEdge(){

}

void printGraph(){

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
