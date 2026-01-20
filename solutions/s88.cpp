#include "lib.h"

using namespace std;

class Solution {
public:
    
    bool dfs(vector<vector<int>> &edges, unordered_set<int> &routes, unordered_set<int> &learned, int course) {
        if (routes.count(course)) return false;
        if (learned.count(course)) return true;
        routes.insert(course);
        for (int dep : edges[course]) {
            if (!dfs(edges, routes, learned, dep)) return false;
        }
        routes.erase(course);
        learned.insert(course);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        for (auto p : prerequisites) {
            edges[p[1]].push_back(p[0]);
        }
        unordered_set<int> routes;
        unordered_set<int> learned;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(edges, routes, learned, i)) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
