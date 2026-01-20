#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode *mergeList(ListNode *h1, ListNode *h2) {
        ListNode ans;
        ListNode *cur = &ans;
        while(h1 && h2) {
            if (h1->val < h2->val) {
                cur->next = h1;
                h1 = h1->next;
            } else {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        if (h1) {
            cur->next = h1;
        }
        if (h2) {
            cur->next = h2;
        }
        return ans.next;
    }
    ListNode *split(ListNode *head, int n) {
        while(--n && head) head = head->next;
        if (!head) return nullptr;
        ListNode *rest = head->next;
        head->next = nullptr;
        return rest;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;

        int n = 0;
        ListNode *tmp = head;
        while (tmp) {
            tmp = tmp->next;
            n++;
        }

        ListNode ans(0, head);
        for (int sublen = 1; sublen < n; sublen <<= 1) {
            ListNode *pre = &ans;
            ListNode *cur = pre->next;
            while (cur) {
                ListNode *h1 = cur;
                ListNode *h2 = split(h1, sublen);
                ListNode *rest = split(h2, sublen);
        
                pre->next = mergeList(h1, h2);
                while(pre->next) {
                    pre = pre->next;
                }
                cur = rest;
            }
        }

        return ans.next;
        // if (head == nullptr) return nullptr;
        // if (head->next == nullptr) return head;
        // ListNode *pivot = head;
        // ListNode *fast = head->next;
        // while(fast && fast->next) {
        //     pivot = pivot->next;
        //     fast = fast->next->next;
        // }
        
        // ListNode* next = pivot->next;
        // pivot->next = nullptr;
        // head = sortList(head);
        // next = sortList(next);
        // ListNode ans;
        // ListNode *cur = &ans;
        // while(head && next) {
        //     if (head->val < next->val) {
        //         cur->next = head;
        //         head = head->next;
        //     } else {
        //         cur->next = next;
        //         next = next->next;
        //     }
        //     cur = cur->next;
        // }
        // if (head) {
        //     cur->next = head;
        // }
        // if (next) {
        //     cur->next = next;
        // }
        // return ans.next;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};
    ListNode h4(3);
    ListNode h3(1, &h4);
    ListNode h2(2, &h3);
    ListNode h1(4, &h2);
    s.sortList(&h1);
    return 0;
}
