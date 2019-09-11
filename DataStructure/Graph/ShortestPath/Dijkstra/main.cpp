#include <iostream>

using namespace std;

/***
��Դ���·�����⣺��һ�����㵽�����������̾���
    ���֣�
        ����������֮������·��
        �����ж����֮�����̾���

�㷨�������£�
1. ��ʼ��һ������S����¼��������·���Ķ���
2. ��ʼ��Դ�㵽��������ľ�������d
3. �� V-S ��ѡ��һ����δ�õ����·���Ķ���j d[j] ��С��j������S��
4. ��ʱ����j�Ѿ������Դ�㵽�����·���Ķ����ˣ�������Ҫ��������������·������Ϣ�������������㵽Դ������·����
5. ���·����ǣ�������� d[k] > arc[k][j] + d[j]����ô d[k] = arc[k][j] + d[j]
6. �ظ�3-5���裬ֱ��S�������еĶ��㡣

������Դ���ӣ�https://blog.csdn.net/YF_Li123/article/details/74090301

***/


const int INF = 1000000000;

/*Dijkstra�㷨������ǵ�Դ���·�����⣬������ͼG(V,E)�����s(����ֳ�ΪԴ��),
������s���������������̾��룬������̾���洢�ھ���d��*/
void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool>& vis, vector<int>& d)
{
       /*
       param
       n��           �������
       s��           Դ��
       G��           ͼ���ڽӾ���
       vis��         ��Ƕ����Ƿ��ѱ�����
       d��           �洢Դ��s���������������̾���
       */
       fill(d.begin(), d.end(), INF);                         //��ʼ����̾������ȫ��ΪINF
       d[s] = 0;                                              //���s��������ľ���Ϊ0
       for (int i = 0; i < n; ++i)
       {
              int u = -1;                                     //�ҵ�d[u]��С��u
              int MIN = INF;                                  //��¼��С��d[u]

              // Ѱ��δ������·���Ľ�㣬����d[j]��С��
              for (int j = 0; j < n; ++j)
              {
                     if (vis[j] == false && d[j] < MIN)
                     {
                           u = j;
                           MIN = d[j];
                     }
              }

              //�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
              if (u == -1)
                     return;

              vis[u] = true;                                  //���u�ѱ�����

              for (int v = 0; v < n; ++v)
              {
                     //�������ж��㣬���vδ������&&u�ܹ�����v&&��uΪ�н�����ʹd[v]����
                     if (vis[v] == false && d[u] + G[u][v] < d[v])
                           d[v] = d[u] + G[u][v];             //����d[v]
              }
       }
}


// ����ʵ�ֵİ汾
void shortestPath(int n, int s, vector<vector<int>> G, vector<bool>& visited, vector<int> dist, vector<int> path){
    copy(dist.begin(), dist.end(), G[s]);   // ��ŵ���˼���ǰ�Դ�����ڽӾ�������һ�еľ��뿽����dist������

    dist[s] = 0;  // Դ�㵽����ľ���Ϊ0��

    for(int i = 0; i < n; i++){
        if(i == s) continue;

        int MIN = INF;
        int u = -1;
        // Ѱ��δ���ʵ���̾���ĵ�
        for(int j = 0; j < n; j++){
            if(!visited[j] && dist[j] < MIN){
                MIN = dist[j];
                u = j;
            }
        }

        if(u == -1) return -1; // ˵��ʣ�µĵ㲢����ͨ

        visted[u] = true;
        for(int k = 0; k < n; k++){
            if(dist[k] > dist[j] + G[k][j] && !visited[k]){
                dist[k] = dist[j] + G[k][j];
                path[k] = j;  // j Ϊ k��Դ�����·����һ��ǰ����㣬�������path���飬���ǿ���ʵ��·���Ļ��ݴ�ӡ��
            }
        }

    }
}

void printPath1(int s, int e, vector<int> path){
    while(e != s){   // ��ӡ����·��
        cout << e << "-";
        e = path[e];
    }
    cout << s << endl;
}

void printPath2(int s, int e, vector<int> path){
    if(s == e){
        cout << s << " " << endl;
        return;
    }
    printPath2(s, path[e]);
    cout << e << " " << endl;
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
