#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int compare(string version1, string version2) {
        int i=0, j=0;
        while(i<version1.size() && j<version1.size()) {
            while(version1[i]=='0') i++;
            while(version2[j]=='0') j++;
            while(version1[i]=='.' || version2[j]=='.') {
                if (version1[i]!=version2[j])
                    break;
                i++;
                j++;
            }
            if (version1[i]!='.' || version2[j]!='.')
                break;
            i++;
            j++;
        }
        return i=version1.size()-1 && j==version2.size()-1;
    }
};