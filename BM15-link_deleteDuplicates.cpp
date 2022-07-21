#include <iostream>

struct ListNode{
    int val;
    struct ListNode *next;
};

class Solution{
public:
    ListNode *deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while(p && p->next) {
            while (p->next && p->val == p->next->val) {
                ListNode *t = p->next;
                p->next = t->next;
                free(t);
            }
            p = p->next;
        }
        return head;
    }
};