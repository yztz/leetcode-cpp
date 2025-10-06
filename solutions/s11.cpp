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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, pair<int, int>> neighbour;
        unordered_set<int> way;
        int end = grid[n - 1][n - 1];
        neighbour.insert({grid[0][0], {0, 0}});

        int t = 0;
        
        while (!way.count(end)) {
            vector<int> tmp_t;
            int min_neg = n * n;
            for (auto &kv : neighbour) {
                if (kv.first <= t) {
                    tmp_t.push_back(kv.first);
                }
                min_neg = std::min(kv.first, min_neg);
            }
            if (!tmp_t.empty()) {
                for (int k : tmp_t) {
                    auto &v = neighbour[k];
                    if (v.first - 1 >= 0 && !way.count(grid[v.first - 1][v.second])) 
                        neighbour.insert({grid[v.first - 1][v.second], {v.first - 1, v.second}});
                    if (v.first + 1 < n && !way.count(grid[v.first + 1][v.second])) 
                        neighbour.insert({grid[v.first + 1][v.second], {v.first + 1, v.second}});
                    if (v.second - 1 >= 0 && !way.count(grid[v.first][v.second - 1])) 
                        neighbour.insert({grid[v.first][v.second - 1], {v.first, v.second - 1}});
                    if (v.second + 1 < n && !way.count(grid[v.first][v.second + 1])) 
                        neighbour.insert({grid[v.first][v.second + 1], {v.first, v.second + 1}});
                    neighbour.erase(k);
                    way.insert(k);
                }
            } else {
                t = min_neg;
                auto &v = neighbour[t];
                if (v.first - 1 >= 0 && !way.count(grid[v.first - 1][v.second])) 
                    neighbour.insert({grid[v.first - 1][v.second], {v.first - 1, v.second}});
                if (v.first + 1 < n && !way.count(grid[v.first + 1][v.second])) 
                    neighbour.insert({grid[v.first + 1][v.second], {v.first + 1, v.second}});
                if (v.second - 1 >= 0 && !way.count(grid[v.first][v.second - 1])) 
                    neighbour.insert({grid[v.first][v.second - 1], {v.first, v.second - 1}});
                if (v.second + 1 < n && !way.count(grid[v.first][v.second + 1])) 
                    neighbour.insert({grid[v.first][v.second + 1], {v.first, v.second + 1}});
                way.insert(t);
                neighbour.erase(t);
            }
        }
        return t;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{0,2}, {1,3}};
    std::cout << s.swimInWater(v) << endl;
    return 0;
}
