#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = head;
        ListNode *slow = head;
        ListNode *pre =  &dummy;
        int tmp  = n;
        while (tmp--) {
            fast = fast->next;
        }
        while(fast) {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;

        return dummy.next;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
