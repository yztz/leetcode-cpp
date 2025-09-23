#include "lib.h"
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;



class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        unsigned long long v_i = 0;
        unsigned long long v_j = 0;

        while (i < version1.size() && j < version2.size()) {
            bool is_v1_dot = version1[i] == '.';
            bool is_v2_dot = version2[j] == '.';
            if (!is_v1_dot) {
                v_i = v_i * 10 + version1[i] - '0';
                i++;
            }
            if (!is_v2_dot) {
                v_j = v_j * 10 + version2[j] - '0';
                j++;
            }
            if (is_v1_dot && is_v2_dot) {
                if (v_i != v_j) {
                    return v_i < v_j ? -1 : 1;
                }
                v_i = v_j = 0;
                i++;j++;
            }
        }
        while (i < version1.size()) {
            if (version1[i] != '.') {
                v_i = v_i * 10 + version1[i] - '0';
            } else {
                if (v_i != v_j) {
                    return v_i < v_j ? -1 : 1;
                }
                v_i = v_j = 0;
            }
            i++;
        }
        while (j < version2.size()) {
            if (version2[j] != '.') {
                v_j = v_j * 10 + version2[j] - '0';
            } else {
                if (v_i != v_j) {
                    return v_i < v_j ? -1 : 1;
                }
                v_i = v_j = 0;
            }
            j++;
        }
        if (v_i != v_j) {
            return v_i < v_j ? -1 : 1;
        }else {
            return 0;
        }
    }
};

int main() {

    return 0;
}
