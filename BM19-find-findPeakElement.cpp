#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    int findPeakElement(vector<int> &nums) {
        int low=0, high = nums.size();
        int mid = (low + high) / 2;
        while(low<high && mid>0 && mid<nums.size()-1) {
            if (nums[mid]<nums[mid+1])
                low = mid + 1;
            else if (nums[mid]<nums[mid-1])
                high = mid;
            mid = (low + high) / 2;
        }
        return mid;
    }
};