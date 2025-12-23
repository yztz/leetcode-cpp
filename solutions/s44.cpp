#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* cur = head;
        ListNode* next = cur->next;
        cur->next = nullptr;

        while(cur && next) {
            ListNode* tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }

    ListNode* reverseList_recursion(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto last = head->next;
        auto ret = reverseList(head->next);
        last->next= head;
        head->next = nullptr;

        return ret;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
