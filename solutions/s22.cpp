#include "lib.h"

using namespace std;

// class Solution {
// public:
//     string findSmallestString(string &s, int a) {
//         vector<int> adds = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//         int n = s.length();
//         for (int i = 0; i < n; i++) {
//             int num = s[i] - '0';
//             int nmin = num;
//             vector<int> next_adds;
//             for (int add : adds) {
//                 if ((add * a + num) % 10 < nmin) {
//                     next_adds.clear();
//                     nmin = (add * a + num) % 10;
//                     next_adds.push_back(add);
//                 } else if ((add * a + num) % 10 == nmin) {
//                     next_adds.push_back(add);
//                 }
//             }
//             adds = next_adds;
//             s[i] = nmin + '0';
//         }
//         return s;
//     }

//     string findLexSmallestString(string s, int a, int b) {
//         int n = s.length();
//         if (b % 2 == 0) {
//             int min_idx = -1;;
//             string even(n / 2, '9');
//             // 0 1 2 3
//             for (int i = 0; i < n; i+=2) {
//                 string c = "";
//                 for (int j = 0; j < n / 2; j++) {
//                     c += s[(i + j * 2) % n];
//                 }
//                 if (c < even) {
//                     even = c;
//                     min_idx = i;
//                 }
//             }
//             string odd = "";
//             for (int i = 0; i < n / 2; i++) {
//                 odd += s[(min_idx + 1 + 2 * i) % n];
//             }
//             findSmallestString(odd, a);
//             string ans = "";
//             for (int i = 0; i < n / 2; i++) {
//                 ans += even[i];
//                 ans += odd[i];
//             }
//             return ans;
//         } else {
//             string ans = s;
//             for (int i = 0; i < n; i++) {
//                 int target_i = n - (b * i) % n;
//                 string tmp_s = s.substr(target_i, n - target_i) + s.substr(0, target_i);
//                 string odd, even;
//                 for (int i = 0; i < n; i++) {
//                     if (i % 2 == 0) {
//                         even += tmp_s[i];
//                     } else {
//                         odd += tmp_s[i];
//                     }
//                 }
//                 findSmallestString(odd, a);
//                 findSmallestString(even, a);
//                 tmp_s = "";
//                 for (int i = 0; i < n / 2; i++) {
//                     tmp_s += even[i];
//                     tmp_s += odd[i];
//                 }
//                 if (tmp_s < ans) {
//                     ans = tmp_s;
//                 }
//             }
//             return ans;
//         }

//         return "";
//     }
// };

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        vector<int> vis(n);
        string res = s;
        // 将 s 延长一倍，方便截取轮转后的字符串 t
        s = s + s;
        for (int i = 0; vis[i] == 0; i = (i + b) % n) {
            vis[i] = 1;
            for (int j = 0; j < 10; j++) {
                int k_limit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= k_limit; k++) {
                    // 每次进行累加之前，重新截取 t
                    string t = s.substr(i, n);
                    for (int p = 1; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    }
                    res = min(res, t);
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector v = {15,8,19};
    vector v2 = {38,36,23};

    return 0;
}
