#include <iostream>
#include <stack>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};
using namespace std;

class Solution{
public:
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        stack<ListNode*> s1, s2;
        ListNode *p=head1, *q=head2;
        while(p) {
            s1.push(p);
            p = p->next;
        }
        while(q) {
            s2.push(q);
            q = q->next;
        }
        int flag = 0;
        ListNode *root = new ListNode(0);
        while(!s1.empty() || !s2.empty()) {
            int sum = 0;
            if (s1.empty()) { sum = s2.top()->val + flag; s2.pop(); }
            else if (s2.empty()) { sum = s1.top()->val + flag; s1.pop(); }
            else { sum = s1.top()->val + s2.top()->val + flag; s1.pop(); s2.pop(); }
            flag = sum / 10;
            ListNode *t = new ListNode(sum % 10);
            t->next = root->next;
            root->next = t;
        }
        if (flag) {
            root->val = 1;
            return root;
        } else {
            return root->next;
        }
    }
};