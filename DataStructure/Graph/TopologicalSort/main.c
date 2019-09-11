#include <stdio.h>
#include <stdlib.h>

/**
拓扑排序是针对有向无环图的一种顶点排序算法。
图的一个拓扑排序定义为：
1. 每个顶点都出现，且只有一次
2. 拓扑序列中A如果出现在B之前，那么不存在从B到A的路径。

算法步骤为：
1. 从DAG中选择一个没有前驱结点作为输出
2. 从图中删除该顶点和所有以其为起点的有向边
3. 重复步骤1，2，直到无DAG图结点或者不存在无前驱结点为止。后者说明存在环。
**/

bool topologicalSort(Graph G){
    S = InitStack();   // 初始化栈，存储入度为0的结点
    for(int i = 0; i < G.vexNum; i++){   // 遍历所有结点，将所有入度为0的结点入栈
        if(indegree[i] == 0) S.push(i);
    }
    int count = 0;
    while(!S.empty()){
        int i = S.pop();   // 弹出栈顶元素
        print[count++] = i;// 输出结果存入数组
        for(int p = G.vertices[i].firstarc; p = p->nextarc){ // 遍历结点i的边
            int v = p->adjvex;  // 存储邻接结点
            if(!(--indegree[v])){
                S.push(v);      // 入度为0，则入栈
            }
        }
    }
    if(count <= G.vexNum){
        return false;
    }
    return true;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
