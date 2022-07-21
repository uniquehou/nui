#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode (int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead || !pHead->next) return pHead;
        ListNode *root = new ListNode(0);
        root->next = pHead;
        ListNode *p = root->next, *q;
        while (p->next) {
            q = p->next;
            p->next = q->next;
            q->next = root->next;
            root->next = q;
        }
        return root->next;
    }
};