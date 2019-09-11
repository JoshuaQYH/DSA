#include <stdio.h>
#include <stdlib.h>

/**
������������������޻�ͼ��һ�ֶ��������㷨��
ͼ��һ������������Ϊ��
1. ÿ�����㶼���֣���ֻ��һ��
2. ����������A���������B֮ǰ����ô�����ڴ�B��A��·����

�㷨����Ϊ��
1. ��DAG��ѡ��һ��û��ǰ�������Ϊ���
2. ��ͼ��ɾ���ö������������Ϊ���������
3. �ظ�����1��2��ֱ����DAGͼ�����߲�������ǰ�����Ϊֹ������˵�����ڻ���
**/

bool topologicalSort(Graph G){
    S = InitStack();   // ��ʼ��ջ���洢���Ϊ0�Ľ��
    for(int i = 0; i < G.vexNum; i++){   // �������н�㣬���������Ϊ0�Ľ����ջ
        if(indegree[i] == 0) S.push(i);
    }
    int count = 0;
    while(!S.empty()){
        int i = S.pop();   // ����ջ��Ԫ��
        print[count++] = i;// ��������������
        for(int p = G.vertices[i].firstarc; p = p->nextarc){ // �������i�ı�
            int v = p->adjvex;  // �洢�ڽӽ��
            if(!(--indegree[v])){
                S.push(v);      // ���Ϊ0������ջ
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
