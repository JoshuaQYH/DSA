#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack>
#include <queue>
#define MaxVertexNum 100  // ���Ķ�����
/***

ע�������޷����У������ṩʵ��˼·��α����

��������Ҫ�ǰ���ѧϰͼ�Ŀ�����������������������
C����ȱ�ٶ�����صı�׼�⣬��ȻҲ�����Լ�����ʵ�֣�����������ҪĿ�����˽����ѺͿ��ѣ�
���Խ��ṩ����α�����ʵ�֣�������ϸ��ע�͡�
****/

// �ڽӾ����ʾ��
typedef struct{
    int Vex[MaxVertexNum];                 //�����
    int Edge[MaxVertexNum][MaxVertexNum];  //�߱�
    int vexNum, arcNum;                    // ͼ��ǰ�Ķ������ͻ���
}Graph;


/*************
��������㷨˼·��
1 ��һ����ʼ����v�������ȷ���v���
2 Ȼ����� v ����δ���ʹ����ڽӽ�� a b c d....
3 �����η��� a b c d ... ����δ���ʹ��Ľ��
4 ֱ�����н�㶼���ʹ�Ϊֹ
����һ�ֲַ���ҵĹ��̣�˼·�����ڶ������Ĳ�������������Ĺ���ʵ����ʱ�õ���һ��������ȱ�����

��������˼·��������Ҫ��
1 ����һ�����������������洢�շ��ʽ�������δ�����ڽӽ��
2 ʹ��һ�������������ʾ����Ƿ񱻷��ʹ�

���ܷ�����
- �ռ临�Ӷ�
  �����ǲ����ڽӱ�����ڽӾ���ķ�ʽ��BFS�㷨����Ҫ����һ����������Q��
  n ����㶼��Ҫ���һ�Σ��ռ临�Ӷ�ΪO(n)

- ʱ�临�Ӷȷ���
  ������õ����ڽӾ���Ĵ洢��������ÿһ���������һ��DFS�����Ӷ�ΪO(n),
  ��ÿһ��DFS�в���ÿ��������ڽӵ������ʱ��ΪO(n),���ܵ�ʱ�临�Ӷ�ΪO(n^2)

  �������ڽӱ�Ĵ洢��ʽ����ô��ÿһ���������һ��DFS�����Ӷ�ΪO(n)��
  ����������ʱ��ÿһ�������ٱ�����һ�Σ����Ӷ�ΪO(m) mΪͼ�б�����
  �ܵĸ��Ӷ�ΪO(n + m)
*************/

bool visited[MaxVertexNum];  // �������

void BFSTraverse(Graph G){
    for(int i = 0; i < MaxVertexNum; i++){
        visited[i] = false;
    }
    Queue Q = InitQueue();  // ��ʼ��һ����������
    for(int i = 0; i < G.vexNum; i++){  // ��ÿһ��ͼ��ÿһ��������һ�ο���
        if(!visited[i])
            BFS(G, i, Q);
    }
}

void BFS(Graph G, int vertexNum, Queue Q){
    // ��vertexNum��������������ȱ���ͼG
    // �ȷ�����ʼ����ֵ
    visit(G->Vex[vertexNum]);
    // �����ѷ���
    visited[vertexNum] = true;
    Q.Enqueue(vertexNum);  // ������
    while(!Q.Empty()){
        int v = Q.Dequeue() // ������
        for(int i = 0; i < G.vexNum; i++){
            if(G->Edge[v][i] == 1 && !visited[i]){
                // ��������δ���ʹ����ڽӽ�㣬�������ѷ��ʣ��������
                viisited(G->Vex[i]);
                visited[i] = true;
                Q.Enqueue(i);
            }
        }
    }
}

// BFS��ⵥԴ���·������
// �ڷǴ�Ȩͼ�У�������������·�����Ǳ������ٵ�·����
void BFS_MIN_Distance(Graph G, int u){
    // distance[i]��ʾ u �� i �����·��
    int distance[MaxVertexNum];
    int DEFINITE = 65535;
    for(int i = 0; i < G.vexNum; i++){
        distance[i] = DEFINITE;
        visited[i] = false;
    }
    visited[u] = true;
    distance[u] = 0;
    Queue Q = initQueue();
    Q.Enqueue(Q, u);   // ������
    while(!Q.Empty()){
        int v = Q.Dequeue();
        for(int i = 0; i < G.vexNum; i++){
            if(G->Edge[v][i] == 1 && !visited[i]){
                distance[i] = distance[v] + 1;  // ���ѷ��ʵĽ��֮�� + 1��
                visited[i] = true;
                Q.Enqueue(i);
            }
        }
    }
}

/******************
������������㷨����˼�����£�
1. ���ȷ���ͼ�е�һ�����v
2. Ȼ����v������������v�ڽ���δ���ʵ���һ���w���ٷ�����w�ڽ���δ�����ʵ�һ������x���ظ���������
3. ����������������֮������Ҫ�˻���������ʽ�㣬������������δ���ʵ��ڽӽ�㣬������������
4. ֱ��ͼ�����н�㶼������λ�á�

���ѿ���ֱ��ʹ�õݹ�ʵ�֣����ܷ������£�
- �ռ临�Ӷ�
    �ݹ��㷨����Ҫһ���ݹ鹤��ջ���ռ临�Ӷ�Ϊ O(n)  ��nΪ������)
- ʱ�临�Ӷ�
    �������ڽӾ����ʾ������ÿ���ڽӶ����ʱ��ΪO(n)���ܵ�ʱ�临�Ӷ�ΪO(n^2)
    �������ڽӱ��ʾ���������ж�����ڽӵ�����ʱ��ΪO(m)��mΪ����)�����ʶ���ʱ��ΪO(m)����ʱ�临�Ӷ�ΪO(m + n)
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
    // ���ʵ�ǰ���
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
