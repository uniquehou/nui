#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct aaa {
    int a;
    int b;
    aaa(int x, int y): a(x), b(y) {}
};

int main() {
    vector<int> a{1,2,3,4,5};
    a.insert(a.begin()+3, 10);
    cout << a[3] << endl;
    for(auto item: a)
        cout << item << " ";
    return 0;
}