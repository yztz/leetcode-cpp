#include "lib.h"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0 ; i< k; i++) {
            if (!q.empty()) {
                if (nums[i] > q.front()) {
                    q.clear();
                } else {
                    while(q.back() < nums[i]) {
                        q.pop_back();
                    }
                }
            }
            q.push_back(nums[i]);
        }
        vector<int> ans;
        ans.push_back(q.front());
        for (int i = 1; i + k <= n; i++) {
            int num = nums[i + k - 1];
            if (q.front() == nums[i - 1]) {
                q.pop_front();
            }
            if (num > q.front()) {
                q.clear();
            } else {
                while(q.back() < num) {
                    q.pop_back();
                }
            }
            q.push_back(num);
            ans.push_back(q.front());
        }
        return ans;
        // priority_queue<int> q;
        // unordered_map<int, int> pops;
        // for (int i = 0 ; i< k; i++) {
        //     q.push(nums[i]);
        // }
        // vector<int> ans;
        // ans.push_back(q.top());
        // for (int i = 1; i + k <= n; i++) {
        //     if (nums[i - 1] == q.top()) q.pop();
        //     else pops[nums[i - 1]]++;
        //     while (pops.count(q.top()) && pops[q.top()] > 0) {
        //         pops[q.top()]--;
        //         q.pop();
        //     }
        //     q.push(nums[i + k - 1]);
        //     ans.push_back(q.top());
        // }
        // return ans;
    }
};

int main() {
    Solution s;
    vector v = {9,10,9,-7,-4,-8,2,-6};
    vector v2 = {38,36,23};
    s.maxSlidingWindow(v, 5);
    return 0;
}
