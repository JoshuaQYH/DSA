#include <iostream>
#include <stack>
#include <string>
using namespace std;


/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        stack<char> S;
        for(int i = 0; i < s.length(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                S.push(s[i]);
            }
            else{
                if(S.empty()){
                    return false;
                }
                else{
                    if((S.top() == '(' && s[i] == ')') ||
                       (S.top() == '[' && s[i] == ']') ||
                       (S.top() == '{' && s[i] == '}')
                       ){
                        S.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return S.empty();
    }
};


int main()
{
    Solution s;
    string str = "()[]{}[";
    cout << str << " " << s.isValid(str) << endl;
    str = "{[]}()";
    cout << str << " " << s.isValid(str) << endl;
    return 0;
}
