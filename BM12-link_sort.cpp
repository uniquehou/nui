#include <iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* quicksort(ListNode *start, ListNode* end) {
        ListNode *p = start->next, *q;
        ListNode *root = new ListNode(0);
        root->next = start;
        while(p!=end) {
            if (p->val <= start->val) {
                q = p->next;
                p->next = q->next;
                q->next = root->next;
                root->next = q;
            }
            p = p->next;
        }
        return root->next;
    }

    ListNode* quick(ListNode* start, ListNode* end) {
        while(start!=end) {
            ListNode *m = start;
            start = quicksort(start, end);
            quick(start, m);
            quick(m->next, end);
            if (start->next == end && start->val < end->val) break;
        }
        return start;
    }

    ListNode* sortInList(ListNode *head) {
        return quick(head, nullptr);
    }
};