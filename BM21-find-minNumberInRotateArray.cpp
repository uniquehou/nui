#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findmin(vector<int> &nums, int start, int end) {
        int left=0, right=nums.size();
        int mid = (left + right) / 2;
        while(left < right) {
            if (nums[mid+1]<nums[mid])    // 右边小
                return mid;
            int tmp1 = findmin(nums, start, mid-1);
            int tmp2 = findmin(nums, mid+1, end);
            return min(tmp1, tmp2);
        }
        return left;
    }

    int minNumberInRotateArray(vector<int> rotateArray) {
        // 2 3 4 5 1
        // 3 4 5 1 2
        // 5 1 2 3 4
        return findmin(rotateArray, 0, rotateArray.size());
    }
};