#include "lib.h"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> heads;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (heads.count(num + 1)) {
                heads[num] = heads[num + 1] + 1;
                heads.erase(num + 1);
            } else {
                heads[num] = 1;
            }
        }
        for (auto const &[num, cnt] : heads) {
            int tmp = cnt;
            int next = num + cnt - 1;
            while(next != num && heads.count(next)) {
                tmp += heads[next];
                if (heads[next] == 1) break;
                next = next + heads[next] - 1;
            }
            ans = max(ans, tmp);
        }
        return ans;
        // unordered_map<int, int> head2tail;
        // unordered_map<int, int> tail2head;
        // int ans = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     int num = nums[i];
        //     if (head2tail.count(num) || tail2head.count(num)) continue;
        //     bool next = head2tail.count(num + 1);
        //     bool prev = tail2head.count(num - 1);

        //     if (next && !prev) {
        //         int tail = head2tail[num + 1];
        //         head2tail.erase(num + 1);
        //         head2tail[num] = tail;
        //         tail2head[tail] = num;
        //         ans = max(ans, tail - num + 1);
        //     } else if (!next && prev) {
        //         int head = tail2head[num - 1];
        //         tail2head.erase(num - 1);
        //         tail2head[num] = head;
        //         head2tail[head] = num;
        //         ans = max(ans, num - head + 1);
        //     } else if (next && prev) {
        //         int head = tail2head[num - 1];
        //         int tail = head2tail[num + 1];
        //         tail2head.erase(num - 1);
        //         head2tail.erase(num + 1);
        //         head2tail[head] = tail;
        //         tail2head[tail] = head;
        //         ans = max(ans, tail - head + 1);
        //     } else {
        //         head2tail[num] = num;
        //         tail2head[num] = num;
        //         ans = max(ans, 1);
        //     }
        // }

        // return ans;
    }
};

int main() {
    Solution s;
    vector v = {1,0,1,2};
    vector v2 = {38,36,23};
    s.longestConsecutive(v);
    return 0;
}
