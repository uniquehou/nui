// BM42 用两个栈实现队列
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};