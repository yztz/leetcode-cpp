#include "lib.h"

using namespace std;

class Solution {
struct PointerCompare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[1] != b[1]) {
            return a[1] > b[1];
        } else {
            return a[2] > b[2];
        }
    }
};
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b)->bool{
            return a[0] < b[0];
        });
        priority_queue<vector<int>, vector<vector<int>>, PointerCompare> ongoing;
        int ans = 0;
        int value_max = 0;
        for (int i = 0; i < events.size(); i++) {
            auto &event = events[i];
            while(!ongoing.empty()) {
                auto &t = ongoing.top();
                if (t[1] < event[0]) {
                    value_max = max(value_max, t[2]);
                    ongoing.pop();
                } else {
                    break;
                }
            }
            ans = max(ans, event[2] + value_max);
            ongoing.push(std::move(event));
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{1,3,2},{4,5,2},{2,4,3}};
    vector v2 = {38,36,23};
    int ret = s.maxTwoEvents(v);
    cout << ret << endl;
    return 0;
}
