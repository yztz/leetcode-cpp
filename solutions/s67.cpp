#include "lib.h"

using namespace std;

class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *l = head;
        ListNode *r = head;
        ListNode *newhead = nullptr;
        ListNode *pretail = nullptr;
        
        int count = 1;
        while(r != nullptr) {
            if (count == k) {
                if (newhead == nullptr) newhead = r;
                if (pretail != nullptr) pretail->next = r;
                pretail = l;
                while(l != r) {
                    ListNode *next = l->next;
                    l->next = r->next;
                    r->next = l;
                    l = next;
                }
                l = r = pretail->next;
                count = 1;
            } else {
                r = r->next;
                count++;
            }
        }
        return newhead;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
