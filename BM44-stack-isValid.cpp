// BM44 有效括号序列
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for (char ch: s) {
            if (ch=='[' || ch=='{' || ch=='(')
                s1.push(ch);
            else {
                if (s1.empty()) return false;
                char t = s1.top();
                if (t=='(' && ch==')' || t=='[' && ch==']' || t=='{' && ch=='}')
                    s1.pop();
                else
                    return false;
            }
        }
        return s1.empty();
    }
};