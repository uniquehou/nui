// BM50 两数之和
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> towSum(vector<int> &numbers, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<numbers.size(); i++) {
            if (map.find(target-numbers[i])!=map.end())
                return {map[target-numbers[i]]+1, i+1};
            else
                map[numbers[i]] = i;
            cout << i;
        }
        return {0, 0};
    }
};