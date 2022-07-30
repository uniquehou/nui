// BM54 三数之和
// 思路：先排序，然后遍历数组，遍历后元素后面用双指针找target-nums[i]。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        if (num.size()<3) return {};
        sort(num.begin(), num.end());
        int n = num.size();
        vector<vector<int>> res;
        for(int i=0; i<n; i++) {
            int low = i+1, high=n-1;
            while(low<high) {
                if (num[low]+num[high] == -num[i]) {
                    res.push_back({num[i], num[low], num[high]});
                    while(num[low+1]==num[low] && low<n) low++;
                    while(num[high-1]==num[high] && high>i) high--;
                    low++;
                    high--;
                } else if (num[low]+num[high] < -num[i]) {
                    while(num[low+1]==num[low] && low<n) low++;
                    low++;
                } else {
                    while(num[high-1]==num[high] && high>i) high--;
                    high--;
                }
            }
            while(num[i+1]==num[i] && i<n) i++;
        }
        return res;
    }
};