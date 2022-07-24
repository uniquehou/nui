// BM43 包含min函数的栈
#include <iostream>
#include <stack>

class Solution {
public:
    void push(int value) {
        s.push(value);
        if (min_s.empty())
            min_s.push(value);
        else
            min_s.push( min()<value? min(): value );
    }

    int pop() {
        int node = -1;
        if (!s.empty()) {
            node = top();
            s.pop();
            min_s.pop();
        }
        return node;
    }

    int top() {
        return s.top();
    }

    int min() {
        return min_s.top();
    }

private:
    stack<int> s, min_s;
}