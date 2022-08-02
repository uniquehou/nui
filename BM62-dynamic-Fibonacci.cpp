// BM62 斐波那契数列
#include <iostream>

class Solution {
public:
    int Fibonacci(int n) {
        if (n<=2) return 1;
        int p = 1, q = 1, m = 1;
        for(int i=3; i<=n; i++) {
            m = p;
            p = q;
            q += m;
        }
        return q;
    }
};