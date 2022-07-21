#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution{
public:
    ListNode* FindKthToTail(ListNode *pHead, int k) {
        ListNode *p = pHead, *q = pHead;
        int i;
        for(i=0; i<k && p; i++)
            p = p->next;
        if (!p) return i==k? q: nullptr;
        while(p) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};