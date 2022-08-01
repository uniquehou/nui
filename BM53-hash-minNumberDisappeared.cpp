// BM53 缺失的第一个正整数
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class Solution{
public:
    int minNumberDisappeared(vector<int> &nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if (nums[i]<=0)
                nums[i] = n+1;
        }
        for(int i=0; i<n; i++) {
            if (nums[i]<n+1 && nums[ abs(nums[i])-1 ]>0) {
                nums[ abs(nums[i])-1 ] = -nums[ abs(nums[i])-1 ];
            }
        }
        for(int i=0; i<n; i++) {
            if (nums[i]>0 || nums[i]==n+1)
                return i+1;
        }
        return n+1;
    }
};