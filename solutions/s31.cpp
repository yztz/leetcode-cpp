#include "lib.h"

using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // vector<int> ans;
        map<int, vector<pair<int, int>>> meets;
        unordered_set<int> known = {0, firstPerson};
        for (auto &m : meetings) {
            if (!meets.count(m[2])) {
                meets[m[2]] = vector<pair<int, int>>{};
            }
            meets[m[2]].push_back(make_pair(m[0], m[1]));
        }

        for (auto &m : meets) {
            int t = m.first;
            auto ms = m.second;
            while(true) {
                bool flag = false;
                for (int i = 0; i < ms.size(); i++) {
                    int p1 = ms[i].first;
                    int p2 = ms[i].second;
                    bool k1 = known.count(p1);
                    bool k2 = known.count(p2);
                    if ((k1 && !k2) || (!k1 && k2)) {
                        known.insert(p1);
                        known.insert(p2);
                        flag = true;
                    }
                }
                if (!flag) break;
            }
        }


        return std::vector<int>(known.begin(), known.end());
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
