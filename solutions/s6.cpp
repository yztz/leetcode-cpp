#include "lib.h"
#include <algorithm>
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
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        for (auto & p1 : points) {
            for (auto & p2 : points) {
                for (auto & p3 : points) {
                    double tmp = std::abs(p2[0] - p3[0]) * std::abs(p1[1] - p2[1] - (double)(p3[1] - p2[1])/(p3[0] - p2[0])*(p1[0] - p2[0]));
                    if (area < tmp) {
                        area = tmp;
                    }
                }
            }
        }
        return area / 2;
    }
};

int main() {
    Solution s;
    return 0;
}
