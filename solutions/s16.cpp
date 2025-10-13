#include "lib.h"
#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <numeric>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int prev[27] = {0};
        vector<string> ans;
        string *prev_word = &words[0];
        for (char c : *prev_word) {
            prev[c - 'a']++;
        }

        int i = 1;
        while(i < words.size()) {
            string &word = words[i];
            if (prev_word->compare(word) != 0) {
                int cur[27] = {0};
                for (char c : word) {
                    cur[c - 'a']++;
                }
                for (int i = 0; i < 27;i++) {
                    if (cur[i] != prev[i]) {
                        memmove(prev, cur, sizeof(prev));
                        ans.push_back(*prev_word);
                        prev_word = &word;
                        break;
                    }
                }
            }
            i++;
        }
        ans.push_back(*prev_word);

        return ans;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};
    // auto ans = s.successfulPairs(v,v2, 328);
    // s.avoidFlood(v);
    // std::cout <<  << endl;
    return 0;
}
