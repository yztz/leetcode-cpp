#include "lib.h"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // qm qn qk
        // m = qm + qk
        // n = qn + qk
        // m - n = qm - qn
        // int m = 0;
        // int n = 0;
        // ListNode *tmp = headA;
        // while(tmp) {
        //     tmp = tmp->next;
        //     m++;
        // }
        // tmp = headB;
        // while(tmp) {
        //     tmp = tmp->next;
        //     n++;
        // }
        // while(m > n) {
        //     headA = headA->next;
        //     m--;
        // }
        // while(n > m) {
        //     headB = headB->next;
        //     n--;
        // }
        
        // while (headA != headB && headA && headB) {
        //     headA = headA->next;
        //     headB = headB->next;
        // }

        // return headA == headB ? headA : nullptr;

        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa != pb) {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }

        return pa;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
