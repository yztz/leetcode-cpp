#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *newhead = head->next;
        ListNode* nnext = newhead->next;
        newhead->next = head;
        head->next = swapPairs(nnext);

        return newhead;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
