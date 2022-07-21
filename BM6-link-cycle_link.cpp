#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
};

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *p = head, *q = head;
        p = p->next->next;
        while(p) {
            if (p==q)
                return true;
            if (!p || !p->next) return false;
            p = p->next->next;
            q = q->next;
        }
        return false;
    }
};