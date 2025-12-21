#include "lib.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> word_map;
        for (string &str : strs) {
            auto s = str;
            sort(s.begin(), s.end());
            word_map[s].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto &kv : word_map) {
            ans.emplace_back(std::move(kv.second));
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
