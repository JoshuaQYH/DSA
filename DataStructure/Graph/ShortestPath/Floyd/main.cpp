#include <iostream>

using namespace std;

/***************

 求各个顶点之间最短路径问题

***************/

//floyd 算法，在Dijkstra算法的基础之上在添加一个外循环，故距离数组和访问记录数组必须是二维的，
// 而且每次不需要搜索最小路径，仅仅需要三重循环即可实现
// 直接通过中间点来不断更新两个点之间的最短距离
// 时间复杂度是 O(V^3)

vector<vector<int>> Floyd(vector<vector<int>> G){
    int n = G.size();
    vector<vector<int>> distance = G;   // 二维矩阵，表示两个结点之间的最短距离
    vector<<vector<int>> path(n, vector<int>(n, -1));  // n*n矩阵，用于打印访问路径，初始为1；
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(distance[j][k] > distance[j][i] + distance[i][k]){
                    distance[j][k] = distance[j][i] + distance[i][k];
                    path[j][k] = i;
                }
            }
        }
    }
    displayPath(distance, path);
    return distance;
}



// 原文链接：https://blog.csdn.net/zhujiahui622/article/details/52154545
// 路径格式转换(从点对链接式转换到序列式)
// 结果保存到visitPath中
void getVisitPath(vector<vector<int> > path, vector<int> &visitPath, int startNode, int endNode)
{
    int k = path[startNode][endNode];
    if (k == -1)
    {
        return;
    }
    else
    {
        getVisitPath(path, visitPath, startNode, k);
        visitPath.push_back(k);
        getVisitPath(path, visitPath, k, endNode);
    }
}

// 输出所有节点对之间的最短路径
void displayPath(vector<vector<int> > distance, vector<vector<int>> path)
{
    for (size_t i = 0; i < path.size(); ++i)
    {
        for (size_t j = 0; j < path.size(); ++j)
        {
            // 排除自己和自己 以及 不可达的路径
            if (i != j && distance[i][j] < NO_EDGE)
            {
                vector<int> visitPath;
                getVisitPath(path, visitPath, i, j);
                //包含头尾的完整路径
                //visitPath.insert(visitPath.begin(), i);
                //visitPath.push_back(j);
                cout << "From " << i << " to " << j << "||  ";
                cout << "Distance: " << distance[i][j] << "  ||  Path:  ";
                cout << i << "->";

                for (size_t k = 0; k < visitPath.size(); ++k)
                {
                    cout << visitPath[k] << "->";
                }
                cout << j << endl;
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
