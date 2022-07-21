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
    aaa *a = new aaa(1, 1);
    cout << a->a << endl;
    return 0;
}