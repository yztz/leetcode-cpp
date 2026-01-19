#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        ListNode *ans = new ListNode();
        ListNode *cur = ans;

        while (l1 && l2) {
            int add = l1->val + l2->val + carry;
            carry = add >= 10;
            cur->next = new ListNode(add % 10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int add = l1->val + carry;
            carry = add >= 10;
            cur->next = new ListNode(add % 10);
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2) {
            int add = l2->val + carry;
            carry = add >= 10;
            cur->next = new ListNode(add % 10);
            cur = cur->next;
            l2 = l2->next;
        }

        if (carry) cur->next = new ListNode(1);

        return ans->next;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
