#include <iostream>

using namespace std;

/***
单源最短路径问题：求一个顶点到其他顶点的最短距离
    变种：
        求两个顶点之间的最短路径
        求所有顶点对之间的最短距离

算法过程如下：
1. 初始化一个集合S，记录以求得最短路径的顶点
2. 初始化源点到其他顶点的距离数组d
3. 从 V-S 中选出一个暂未得到最短路径的顶点j d[j] 最小，j不属于S；
4. 此时顶点j已经是求得源点到其最短路径的顶点了，我们需要根据这个顶点最短路径的信息来更新其他顶点到源点的最短路径。
5. 更新方法是；如果顶点 d[k] > arc[k][j] + d[j]，那么 d[k] = arc[k][j] + d[j]
6. 重复3-5步骤，直到S包含所有的顶点。

代码来源链接：https://blog.csdn.net/YF_Li123/article/details/74090301

***/


const int INF = 1000000000;

/*Dijkstra算法解决的是单源最短路径问题，即给定图G(V,E)和起点s(起点又称为源点),
求从起点s到达其它顶点的最短距离，并将最短距离存储在矩阵d中*/
void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool>& vis, vector<int>& d)
{
       /*
       param
       n：           顶点个数
       s：           源点
       G：           图的邻接矩阵
       vis：         标记顶点是否已被访问
       d：           存储源点s到达其它顶点的最短距离
       */
       fill(d.begin(), d.end(), INF);                         //初始化最短距离矩阵，全部为INF
       d[s] = 0;                                              //起点s到达自身的距离为0
       for (int i = 0; i < n; ++i)
       {
              int u = -1;                                     //找到d[u]最小的u
              int MIN = INF;                                  //记录最小的d[u]

              // 寻找未求得最短路径的结点，且其d[j]最小。
              for (int j = 0; j < n; ++j)
              {
                     if (vis[j] == false && d[j] < MIN)
                     {
                           u = j;
                           MIN = d[j];
                     }
              }

              //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
              if (u == -1)
                     return;

              vis[u] = true;                                  //标记u已被访问

              for (int v = 0; v < n; ++v)
              {
                     //遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
                     if (vis[v] == false && d[u] + G[u][v] < d[v])
                           d[v] = d[u] + G[u][v];             //更新d[v]
              }
       }
}


// 个人实现的版本
void shortestPath(int n, int s, vector<vector<int>> G, vector<bool>& visited, vector<int> dist, vector<int> path){
    copy(dist.begin(), dist.end(), G[s]);   // 大概的意思就是把源点在邻接矩阵中那一行的距离拷贝到dist数组中

    dist[s] = 0;  // 源点到自身的距离为0；

    for(int i = 0; i < n; i++){
        if(i == s) continue;

        int MIN = INF;
        int u = -1;
        // 寻找未访问的最短距离的点
        for(int j = 0; j < n; j++){
            if(!visited[j] && dist[j] < MIN){
                MIN = dist[j];
                u = j;
            }
        }

        if(u == -1) return -1; // 说明剩下的点并不连通

        visted[u] = true;
        for(int k = 0; k < n; k++){
            if(dist[k] > dist[j] + G[k][j] && !visited[k]){
                dist[k] = dist[j] + G[k][j];
                path[k] = j;  // j 为 k到源点最短路径的一个前驱结点，利用这个path数组，我们可以实现路径的回溯打印。
            }
        }

    }
}

void printPath1(int s, int e, vector<int> path){
    while(e != s){   // 打印逆序路径
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
