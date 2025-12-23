#include "lib.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode *n1 = head;
        ListNode *n2 = head;
        while(n2 != nullptr) {
            n1 = n1->next;
            n2 = n2->next;
            if (n2 != nullptr) n2 = n2->next;
        }
        // revert
        ListNode *next = n1->next;
        n1->next = nullptr;
        while(n1 && next) {
            auto tmp = next->next;
            next->next = n1;
            n1 = next;
            next = tmp;
        }
        n2 = head;
        while (n1) {
            if (n1->val != n2->val) {
                return false;
            }
            n1 = n1->next;
            n2 = n2->next;
        }

        return true;

    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
