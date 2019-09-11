#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack>
#include <queue>
#define MaxVertexNum 100  // 最大的顶点数
/***

注：代码无法运行，仅仅提供实现思路和伪代码

本代码主要是帮助学习图的宽度优先搜索和深度优先搜索
C语言缺少队列相关的标准库，当然也可以自己定义实现，不过这里主要目的是了解深搜和宽搜，
所以仅提供类似伪代码的实现，附上详细的注释。
****/

// 邻接矩阵表示法
typedef struct{
    int Vex[MaxVertexNum];                 //顶点表
    int Edge[MaxVertexNum][MaxVertexNum];  //边表
    int vexNum, arcNum;                    // 图当前的顶点数和弧数
}Graph;


/*************
广度优先算法思路：
1 从一个起始顶点v出发，先访问v结点
2 然后访问 v 所有未访问过的邻接结点 a b c d....
3 在依次访问 a b c d ... 所有未访问过的结点
4 直到所有结点都访问过为止
这是一种分层查找的过程，思路类似于二叉树的层序遍历，遍历的过程实际上时得到了一个广度优先遍历树

根据以上思路，我们需要：
1 利用一个辅助队列来帮助存储刚访问结点的所有未访问邻接结点
2 使用一个标记数组来表示结点是否被访问过

性能分析：
- 空间复杂度
  不论是采用邻接表或者邻接矩阵的方式，BFS算法都需要借助一个辅助队列Q，
  n 个结点都需要入队一次，空间复杂度为O(n)

- 时间复杂度分析
  这里采用的是邻接矩阵的存储方法，对每一个顶点进行一次DFS，复杂度为O(n),
  在每一次DFS中查找每个顶点的邻接点的所需时间为O(n),故总的时间复杂度为O(n^2)

  若采用邻接表的存储方式，那么对每一个顶点进行一次DFS，复杂度为O(n)，
  搜索任意结点时，每一条边至少被访问一次，复杂度为O(m) m为图中边数。
  总的复杂度为O(n + m)
*************/

bool visited[MaxVertexNum];  // 标记数组

void BFSTraverse(Graph G){
    for(int i = 0; i < MaxVertexNum; i++){
        visited[i] = false;
    }
    Queue Q = InitQueue();  // 初始化一个辅助队列
    for(int i = 0; i < G.vexNum; i++){  // 对每一个图中每一个结点进行一次宽搜
        if(!visited[i])
            BFS(G, i, Q);
    }
}

void BFS(Graph G, int vertexNum, Queue Q){
    // 从vertexNum结点出发，广度优先遍历图G
    // 先访问起始结点的值
    visit(G->Vex[vertexNum]);
    // 设置已访问
    visited[vertexNum] = true;
    Q.Enqueue(vertexNum);  // 结点入队
    while(!Q.Empty()){
        int v = Q.Dequeue() // 结点出队
        for(int i = 0; i < G.vexNum; i++){
            if(G->Edge[v][i] == 1 && !visited[i]){
                // 访问所有未访问过的邻接结点，并设置已访问，将其入队
                viisited(G->Vex[i]);
                visited[i] = true;
                Q.Enqueue(i);
            }
        }
    }
}

// BFS求解单源最短路径问题
// 在非带权图中，两个顶点的最短路径就是边数最少的路径。
void BFS_MIN_Distance(Graph G, int u){
    // distance[i]表示 u 到 i 的最短路径
    int distance[MaxVertexNum];
    int DEFINITE = 65535;
    for(int i = 0; i < G.vexNum; i++){
        distance[i] = DEFINITE;
        visited[i] = false;
    }
    visited[u] = true;
    distance[u] = 0;
    Queue Q = initQueue();
    Q.Enqueue(Q, u);   // 结点入队
    while(!Q.Empty()){
        int v = Q.Dequeue();
        for(int i = 0; i < G.vexNum; i++){
            if(G->Edge[v][i] == 1 && !visited[i]){
                distance[i] = distance[v] + 1;  // 在已访问的结点之上 + 1；
                visited[i] = true;
                Q.Enqueue(i);
            }
        }
    }
}

/******************
深度优先搜索算法基本思想如下：
1. 首先访问图中的一个起点v
2. 然后由v出发，访问与v邻接且未访问的任一结点w，再访问与w邻接且未被访问的一个顶点x，重复上述过程
3. 当不能再向下深搜之后，我们要退回最近被访问结点，若它还有其他未访问的邻接结点，继续上述搜索
4. 直到图中所有结点都被访问位置。

深搜可以直接使用递归实现，性能分析如下：
- 空间复杂度
    递归算法，需要一个递归工作栈，空间复杂度为 O(n)  （n为结点个数)
- 时间复杂度
    若采用邻接矩阵表示，查找每个邻接顶点的时间为O(n)，总的时间复杂度为O(n^2)
    若采用邻接表表示，查找所有顶点的邻接点所需时间为O(m)（m为边数)，访问顶点时间为O(m)，故时间复杂度为O(m + n)
********************/

void DFSTraverse(Graph G){
    for(int i = i; G.vexNum; i++){
        visited[i] = false;
    }
    for(int i = 0; i < G.vexNum; i++){
        if(!visited[i])
            DFS(G, i);
    }
}

void DFS(Graph G, int vertexNum){
    // 访问当前结点
    visit(G->Vex[vertexNum]);
    visited[vertexNum] = true;
    for(int i = 0; i < G.vexNum; i++){
        if(G.Edge[vertexNum][i] == 1 && !visited[i])
            DFS(G, i);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
