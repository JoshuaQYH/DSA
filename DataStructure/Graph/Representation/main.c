#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    VNode* nodeList[MaxVertexNum];  // �����
    int vexNum, arcNum;            // �����ͻ���
    int hasNode[MaxVertexNum];     // ȷ����λ���Ƿ���ڶ���
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
    VNode nodeList[MaxVertexNum];  // �����
    int vexNum, arcNum;            // �����ͻ���
    int hasNode[MaxVertexNum];     // ȷ����λ���Ƿ���ڶ���
}ALGraph;

����ͨ�ڽӱ�Ϊ����ʵ����ͼ�Ĳ���ɾ�����㣬����ɾ����
*/

ALGraph* initGraph(){
    AlGraph *G = (ALGraph*)malloc(sizeof(ALGraph));
    G->vexNum = 0;
    G->arcNum = 0;
    for(int i = 0; i < MaxVertexNum; i++){
        G->hasNode[i] = false;
        G->nodeList[i] = NULL;
    }
    return G;
}


bool addEdge(ALGraph *G, int vertex1, int vertex2, int edgeVal;){
    // 1 -> 2
    if(!G) return false;
    if(!(G->hasNode[vertex1] && G->hasNode[vertex2])) return false;
    VNode *node1 = G->nodeList[vertex1];

    ArcNode *newArc = (ArcNode*)malloc(sizeof(ArcNode));
    newArc->adjVex = vertex2;
    newArc->edgeVal = edgeVal;
    newArc->next = NULL;

    ArcNode *arc = node1->first;
    if(!arc){
        arc = newArc;
        return true;
    }
    while(arc->next){
        arc = arc->next;
    }
    arc->next = newArc;
    return true;
}

bool deleteEdge(ALGraph *G, int vertex1, int vertex2){
    // 1 -> 2
    if(!G) return false;
    if(!(G->hasNode[vertex1] && G->hasNOde[vertex2])) return false;
    VNode *vnode = G->nodeList[vertex1];
    ArcNode *arc = vnode->first;
    if(!arc) return true;
    while(arc->next){
        if(arc->next->adjVex == vertex2){
            ArcNode *tmp = arc->next;
            arc->next = arc->next->next;
            free(tmp);
            break;
        }
    }
    return true;
}

bool addVertex(ALGraph* G, int vertex, int data){
    if(G->vertexNum + 1 == MaxVertexNum) return false;
    if(G->hasNode[vertex]) return false;
    G->vertexNum++;
    VNode *node = (VNode*)malloc(sizeof(ALGraph));
    node->data = data;
    node->first = NULL;
    G->nodeList[vertex] = node;
    return true;
}

bool deleteVertex(ALGraph *G, int vertex){
    if(!G->hasNode[vertex]) return false;
    G->hasNode[vertex] = false;
    VNode *node = G->nodeList[vertex];
    ArcNode *arc = node->first;
    while(arc){
        ArcNode* tmp = arc->next;
        free(arc);
        arc = tmp;
    }
    for(int i = 0; i < MaxVertexNum; i++){
        if(G->hasNode[i]){
            deleteEdge(G, i, vertex);
        }
    }
    return true;
}

void printGraph(){

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
