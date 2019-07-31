#include <iostream>

using namespace std;


/*
��·����ԭ�����£�

1. ��ͷ�� / ��ʼ
2. Ŀ¼֮��ֻ������һ�� /
3. Ŀ¼��β���� / ����
4.  ʹ��.  or .. ���ֵ�ǰĿ¼����һĿ¼��ȥ��.�õ���������·��

ʵ��˼·��
��ʼ��һ���յ�����·�� finalPath ��һ�����Ŀ¼�ַ����� . / ���ŵĶ�ջ��


*/

#include <stack>

class Solution {
public:
    string simplifyPath(string path) {
        //cout << "test" << endl;
        string finalPath = "";
        stack<string> S;
        string dir = "";
        for (int i = 0; i < path.length(); i++){
            //cout << path[i] << endl;
            if(path[i] == '/' && !S.empty() && S.top() == "/") {
                //cout << "1" << endl;
                continue; //
            }
            else if (path[i] == '/' && !S.empty() && S.top() != "/"){
                //cout << "2" << endl;
                S.push("/");
            }
            else if(path[i] == '.' && i + 1 < path.length()&& !S.empty()  && path[i+1] == '.'){
                //cout << "3" << endl;
                S.pop();  // delete /
                S.pop();  // delete top dir;
                i++;
            }
            else if(path[i] == '.' && i + 1 < path.length() && path[i+1] != '.'){
                //cout << "4" << endl;
                continue;
            }
            else if(isLetter(path[i])){
                //cout << "5" << endl;
                dir+= path[i];
                if((i + 1 < path.length() && !isLetter(path[i+1]))
                    || i + 1 == path.length()) {
                    S.push(dir);
                    //cout << dir << endl;
                    dir = "";
                }
            }
        }
        if(!S.empty() && S.top() == "/"){
            S.pop();
        }
        while(!S.empty()){
            // cout << S.top() << endl;
            finalPath = S.top() + finalPath;
            S.pop();
            //cout << finalPath << endl;
        }
        finalPath = "/" + finalPath;
        //cout << finalPath << endl;
        return finalPath;
    }

    bool isLetter(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.simplifyPath("/...") << endl;
    return 0;
}
