// BM46 最小的K个数
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int quick(vector<int>& a, int p, int q) {
        int t = a[p];
        int i=p, j=q+1;
        while(i<j) {
            while(a[++i]<t && i<j);
            while(a[--j]>t);
            if (i<j) swap(a[i], a[j]);
            else break;
        }
        a[p] = a[j];
        a[j] = t;
        return j;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k==0) return {};
        int p=0, q=input.size()-1;
        int m = quick(input, p, q);
        while(m<input.size()) {
            if (m==k || m+1==k)
                return vector<int>({input.begin(), input.begin()+k});
            else if (m<k)
                p = m+1;
            else
                q = m-1;
            m = quick(input, p, q);
        }
        return input;
    }
};

int main() {
    Solution ss;
    ss.GetLeastNumbers_Solution(vector<int>{2,1}, 1);
}