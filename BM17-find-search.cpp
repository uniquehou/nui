#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    int search(vector<int>& a, int t) {
        int low=0, high=a.size();
        int mid = (low + high) / 2;
        while(low<high) {
            if (a[mid]<t)
                low = mid + 1;
            else if (a[mid]>t)
                high = mid;
            else
                return mid;
            mid = (low + high) / 2;
        }
        return -1;
    }
};