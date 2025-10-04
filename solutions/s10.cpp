#include "lib.h"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;

        int ans = 0;

        while(i != j) {
            int current = (j - i) * std::min(height[i], height[j]);
            ans = std::max(ans, current);
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        };

        return ans;
    }
};

int main() {
    Solution s;
    vector v({1,8,6,2,5,4,8,3,7});
    std::cout << s.maxArea(v) << endl;
    return 0;
}
