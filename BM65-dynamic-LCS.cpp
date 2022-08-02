// BM65 最长公共子序列(二)
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string lcs(string s1, int i, string s2, int j) {
        if (i<0 || j<0)
            return "";
        if (s1[i]==s2[j]) {
            return lcs(s1, i-1, s2, j-1) + s1[i];
        } else {
            string res1 = lcs(s1, i-1, s2, j);
            string res2 = lcs(s1, i, s2, j-1);
            return res1.size()>res2.size()? res1: res2;
        }
            
    }
    string LCS(string s1, string s2) {
        string res = lcs(s1, s1.size()-1, s2, s2.size()-1);
        if (res.empty())
            res = "-1";
        return res;
    }
};

int main() {
    string s1 = "1A2C3D4B56";
    string s2 = "B1D23A456A";
    Solution ss;
    cout << ss.LCS(s1, s2) << endl;
}