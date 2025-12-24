#include "lib.h"

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int cnt = 0;
        for (int apple : apples) {
            cnt += apple;
        }
        sort(capacity.begin(), capacity.end(), [](const int&a, const int &b) {
            return a > b;
        });
        int left = cnt;
        int ans = 0;
        for (int c : capacity) {
            if (cnt == 0) {
                break;
            }
            cnt = max(0, cnt - c);
            ans++;
        }
        return ans;

    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
