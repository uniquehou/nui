#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m==n) return head;
        ListNode *root = new ListNode(0);
        root->next = head;
        ListNode *p = root, *q;
        for(int i=0; i<m-1 && p; i++) {
            p = p->next;
        }
        if (!p) return head;
        ListNode *new_root = p;
        p = p->next;
        for(int i=m; i<n; i++) {
            q = p->next;
            p->next = q->next;
            q->next = new_root->next;
            new_root->next = q;
        }
        return root->next;
    }
};