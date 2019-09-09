#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100  // 最大的顶点数
typedef char VertexType  // 结点数据类型
typedef int EdgeType     // 边权值的数据类型

/********************
图的存储表示
1. 普通邻接矩阵表示法
2. 普通邻接表表示法
3. 十字邻接表（有向图）
4. 多重连接表（无向图）
*********************/
// 邻接矩阵表示法
typedef struct{
    VertexType Vex[MaxVertexNum];  //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //边表
    int vexNum, arcNum;   // 图当前的顶点数和弧数
}MGraph;

// 如果使用一维数组来存储**无向图**，那么对于一个顶点Gij,在数组中对应的下标为
// (i * (i + 1) / 2  + j )

// 邻接表表示法
typedef struct ArcNode{
    int adjVex;            // 该弧指向的顶点
    struct ArcNode* next;  // 指向下一条弧
    int edgeVal;           // 网络边权值
}ArcNode;

typedef struct VNode{
    VertextType data;       // 顶点
    ArcNode* first;         // 指向第一个依附该顶点的指针
}VNode;

typedef struct{
    VNode nodeList[MaxVertexNum]; // 顶点表
    int vexNum, arcNum;            // 边数和弧数
}ALGraph;

//  需要注意的是，我们规定入度是由列元素计算的，出度是由行元素计算的。


// 十字链表表示法（针对有向图）
// 在邻接表的基础上发展而来
typedef struct T_ArcNode{    // 边表结点
    int headVex, tailVex;  // 该弧指向的头顶点，尾顶点
    ArcNode *hLink, tLink; // 指向弧头相同 (->A) 和弧尾相同 (A->) 的结点
    int edgeVal;           // 网络边权值
}T_ArcNode;

typedef struct T_VNode{
    VertextType data;       // 顶点表结点
    ArcNode *firstIn, *firstOut;  // 指向第一条入度弧和出度弧
}T_VNode;

typedef struct{
    T_VNode nodeList[MaxVertexNum]; // 顶点表
    int vexNum, arcNum;            // 边数和弧数
}T_Graph;


// 邻接多重表（针对无向图）
// 普通邻接表中确定两个顶点之间是否存在边，需要遍历，效率低；
typedef struct M_ArcNode{
    bool mark;              // 用于搜索标记
    int iVex, jVex;         // 指示两个顶点的位置
    struct L_ArcNode *iLink, *jLink;  // 指示两个顶点的下一条边
}M_ArcNode;

typedef struct L_VNode{
    VertexType data;   // 顶点信息
    L_ArcNode* first;  // 依附顶点的第一条边
}M_VNode;

typedef struct{
    L_VNode nodeList[MaxVertexNum]; // 邻接表
    int vexNum, arcNum;             // 图的顶点数盒弧数
}M_Graph;


/*********************************
图的基本操作
1. 判断图是否存在 x - y 的边
2. 列出与顶点x邻接的边
3. 在图中插入顶点
4. 在图中删除顶点
5. 在图中插入边
6. 在图中删除边
7. 返回顶点的第一个邻接点
8. 获取边对应的权值
9. 设置边对应的权值
**********************************/
/*
typedef struct ArcNode{
    int adjVex;            // 该弧指向的顶点
    struct ArcNode* next;  // 指向下一条弧
    int edgeVal;           // 网络边权值
}ArcNode;

typedef struct VNode{
    VertextType data;       // 顶点
    ArcNode* first;         // 指向第一个依附该顶点的指针
}VNode;

typedef struct{
    VNode nodeList[MaxVertexNum]; // 顶点表
    int vexNum, arcNum;            // 边数和弧数
}ALGraph;

以普通邻接表为例，实现无向图的插入删除顶点，插入删除边
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
