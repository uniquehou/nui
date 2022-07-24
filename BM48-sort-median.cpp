// BM48 数据流中的中位数
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void Insert(int num) {
        if (data.)
        int low=0, high=data.size()-1;
        int mid;
        while(low<=high) {
            mid = (low + high) / 2;
            if (data[mid]==num)
                break;
            else if (data[mid]<num)
                low = mid + 1;
            else
                high = mid;
        }
        data.insert(data.begin()+low, num);
    }

    double GetMedian() {
        int n = data.size();
        if (n%2 == 0)
            return (data[n/2] + data[n/2-1]) / 2.0;
        else
            return data[n/2];
    }

private:
    vector<int> data;
}