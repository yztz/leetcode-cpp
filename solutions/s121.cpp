#include "lib.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> exists;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            int num = s[right];
            while(exists.count(num)) {
                exists.erase(s[left++]);
            }
            exists.insert(num);
            ans = max(ans, (int)exists.size());
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
