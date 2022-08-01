// BM59 N皇后问题
#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    vector<int> queue;
    int res;

    bool check(int t) {
        for(int i=0; i<t; i++)
            if (queue[i]==queue[t] || abs(i-t)==abs(queue[i]-queue[t]))
                return false;
        return true;
    }

    void find(int t, int n) {
        if (t>n)
            res++;
        else
            for(int i=0; i<=n; i++) {
                queue.push_back(i);
                if (check(t)) 
                    find(t+1, n);
                queue.pop_back();
            }
    }

    int Nqueen(int n) {
        res = 0;
        find(0, n-1);
        return res;
    }
};