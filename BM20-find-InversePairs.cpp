// BM20 数组中的逆序对
#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    int merge(vector<int> &data, int left, int mid, int right) {
        if (left>=right) return 0;
        int i=left, j=mid;
        int count = 0;
        count += merge(data, left, (left+mid)/2, mid);
        count += merge(data, mid, (mid+right)/2, right);
        count %= 1000000007;
        vector<int> m(right-left, 0);
        while(i<mid && j<right) {
            if (data[i]<data[j])
                m.push_back(data[i++]);
            else {
                m.push_back(data[j++]);
                count++;
            }
        }
        while(i<mid)
            m.push_back(data[i++]);
        while(j<right) {
            m.push_back(data[j++]);
            count++;
        }
        data.swap(m);
        return count % 1000000007;
    }

    int InversePairs(vector<int> data) {
        return merge(data, 0, data.size()/2, data.size());
    }
};

int main() {
    vector<int> data{1,2,3,4,5,6,7,0};
    Solution ss;
    int n = ss.InversePairs(data);
    cout << n << endl;
    return 0;
}