#include <iostream>

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    bool isPail(ListNode* head) {
        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            p = p->next->next;
            q = q->next;
        }
        if (p) q = q->next;   // odd
        // reverse q
        q->next = nullptr;
        ListNode *next = q->next;
        while(t) {
            t = q->next->next;
            p = q->next;
            p->next = q;
            q = p;
            q = t;
        }
        p = head;
        while(p!=q) {

        }
    }
};

