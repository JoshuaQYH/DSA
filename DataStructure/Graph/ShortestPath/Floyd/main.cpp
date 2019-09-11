#include <iostream>

using namespace std;

/***************

 ���������֮�����·������

***************/

//floyd �㷨����Dijkstra�㷨�Ļ���֮�������һ����ѭ�����ʾ�������ͷ��ʼ�¼��������Ƕ�ά�ģ�
// ����ÿ�β���Ҫ������С·����������Ҫ����ѭ������ʵ��
// ֱ��ͨ���м�������ϸ���������֮�����̾���
// ʱ�临�Ӷ��� O(V^3)

vector<vector<int>> Floyd(vector<vector<int>> G){
    int n = G.size();
    vector<vector<int>> distance = G;   // ��ά���󣬱�ʾ�������֮�����̾���
    vector<<vector<int>> path(n, vector<int>(n, -1));  // n*n�������ڴ�ӡ����·������ʼΪ1��
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



// ԭ�����ӣ�https://blog.csdn.net/zhujiahui622/article/details/52154545
// ·����ʽת��(�ӵ������ʽת��������ʽ)
// ������浽visitPath��
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

// ������нڵ��֮������·��
void displayPath(vector<vector<int> > distance, vector<vector<int>> path)
{
    for (size_t i = 0; i < path.size(); ++i)
    {
        for (size_t j = 0; j < path.size(); ++j)
        {
            // �ų��Լ����Լ� �Լ� ���ɴ��·��
            if (i != j && distance[i][j] < NO_EDGE)
            {
                vector<int> visitPath;
                getVisitPath(path, visitPath, i, j);
                //����ͷβ������·��
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
