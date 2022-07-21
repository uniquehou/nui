#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution{
public:

    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        if (pHead1->val > pHead2->val) return Merge(pHead2, pHead1);
        ListNode *p=pHead1, *q=pHead2, *t;
        while(p->next && q) {
            if (p->val <= q->val && p->next->val > q->val) {
                t = q;
                q = q->next;
                t->next = p->next;
                p->next = t;
            }
            p = p->next;
        }
        if (q)
            p->next = q;
        return pHead1;
    }

    ListNode *mergelist(vector<ListNode*> &lists, int start, int end) {
        if (start==end)
            return lists[start];
        if (start+1==end)
            return Merge(lists[start], lists[start+1]);
        int mid = (start + end) / 2;
        return Merge(mergelist(lists, start, mid), mergelist(lists, mid+1, end));
        
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        return mergelist(lists, 0, lists.size()-1);
    }
};