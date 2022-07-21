#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    int findPeakElement(vector<int> &nums) {
        int low=0, high = nums.size()-1;
        int mid = (low + high) / 2;
        while(low<high) {
            if (low+1==high || low==high) {
                mid = nums[low]>nums[high]? low: high;
                break;
            }
            if (nums[mid]<nums[mid+1])
                low = mid + 1;
            else if (nums[mid]<nums[mid-1])
                high = mid - 1;
            else
                break;
            mid = (low + high) / 2;
        }
        return mid;
    }
};