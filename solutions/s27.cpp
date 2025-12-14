#include "lib.h"

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        int nb = buildings.size();
        // unordered_map<int, unordered_map<int, int>> dots;
        unordered_map<int, set<int>> dots_x;
        unordered_map<int, set<int>> dots_y;

        for (int i = 0; i < buildings.size(); i++) {
            auto &b = buildings[i];
            int x = b[0];
            int y = b[1];
            
            if (!dots_x.count(x)) dots_x[x] = set<int>();
            if (!dots_y.count(y)) dots_y[y] = set<int>();

            dots_x[x].insert(y);
            dots_y[y].insert(x);
        }

        for (int i = 0; i < buildings.size(); i++) {
            auto &b = buildings[i];
            int x = b[0];
            int y = b[1];

            if (dots_x[x].lower_bound(y + 1) != dots_x[x].end() &&
                *(dots_x[x].lower_bound(0)) != y &&
                dots_y[y].lower_bound(x + 1) != dots_y[y].end() &&
                *(dots_y[y].lower_bound(0)) != x
            ) ans++;
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
