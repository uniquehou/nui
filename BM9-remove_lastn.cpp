#include <iostream>

struct ListNode{
    int val;
    struct ListNode *next;
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p=head, *q=head;
        while(n--)
            p = p->next;
        if (!p)
            return q->next;
        while(p->next) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};