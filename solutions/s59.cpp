#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr || list2 == nullptr) return list1 == nullptr ? list2 : list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
        // ListNode *h1 = list1;
        // ListNode *h2 = list2;

        // ListNode ans(-200);
        // ListNode *cur = &ans;

        // while(h1 && h2) {
        //     ListNode *tmp;
        //     if (h1->val <= h2->val) {
        //         cur->next = h1;
        //         cur = h1;
        //         h1 = h1->next;
        //     } else {
        //         cur->next = h2;
        //         cur = h2;
        //         h2 = h2->next;
        //     }
        //     cur->next = nullptr;
        // }

        // if (h1) cur->next = h1;
        // if (h2) cur->next = h2;

        // return ans.next;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
