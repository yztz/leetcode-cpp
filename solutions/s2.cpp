#include "lib.h"
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct pairComparator {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

struct tupleComparator {
    bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) const {
        if (std::get<0>(a) == std::get<0>(b)) {
            if (std::get<1>(a) == std::get<1>(b)) {
                return std::get<2>(a) > std::get<2>(b);
            }
            return std::get<1>(a) > std::get<1>(b);
        }

        return std::get<0>(a) > std::get<0>(b);
    }
};

class Solution {
public:
        // Method 1:
        int maxFrequencyElements(vector<int>& nums) {
            int freq[102] = {0};
            int freq_cnt[102] = {0};
            int max_freq = 1;
            for (int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                freq_cnt[freq[num]]--;
                freq[num]++;
                freq_cnt[freq[num]]++;
                max_freq = std::max(max_freq, freq[num]);
            }

            return freq_cnt[max_freq] * max_freq;
        }

       
};

int main() {

    return 0;
}
