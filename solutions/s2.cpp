#include "lib.h"
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;


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
