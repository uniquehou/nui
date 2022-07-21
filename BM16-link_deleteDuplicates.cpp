#include <iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = new ListNode(0);
        root->next = head;
        ListNode *p = head, *pre = root, *t;
        while(p && p->next) {
            if (p->val != p->next->val) {
                pre = pre->next;
                p = p->next;
            } else {
                while(p->next && p->val == p->next->val) {
                    t = p;
                    p = p->next;
                    free(t);
                }
                pre->next = p->next;
                free(p);
                p = pre->next;
            }
        }
        return root->next;
    }
};