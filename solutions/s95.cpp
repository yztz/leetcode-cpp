#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode* l2) {
        ListNode dummy;
        ListNode *cur = &dummy;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        else cur->next = l2;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        while (lists.size() > 1) {
            ListNode *l1 = lists.back();
            lists.pop_back();
            ListNode *l2 = lists.back();
            lists.pop_back();
            lists.push_back(merge(l1, l2));
        }
        
        return lists[0];
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
