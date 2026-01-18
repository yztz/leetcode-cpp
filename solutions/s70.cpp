#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode *slow = head->next;
        if (slow == nullptr) return nullptr;
        ListNode *fast = slow->next;

        while(fast != slow && fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) fast = fast->next;
            slow = slow->next;
        }
        if (fast == nullptr) return nullptr;
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
