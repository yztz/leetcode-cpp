#include "lib.h"

using namespace std;

class Solution {
public:

    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].size();
        int n = strs.size();
        vector<int> dp(len, 1);
        int lis = 1;

        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                int row = 0;
                while(row < n) {
                    if (strs[row][i] < strs[row][j]) {
                        break;
                    }
                    row++;
                }
                if (row == n) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    lis = max(dp[i], lis);
                }
            }
        }
        


        return len - lis;
    }
};

int main() {
    Solution s;
    vector<string> v = {"deehdecfcgegffegghfhfaagcaaffbfahcfaghgdfggbbddbff","dchhgcbahdbdgbbaafhbgfggcbebfacdebhfgcfaafcgbgbggg","hehdggagfabdfbhegebhaaddcaghhegeegdgegagehhdhheecd","fhbbagbdffedafacbeahddbgagggdafceeabaffhhhhcedcfbh","caaefgdgefeahcgfgccaacdfabdgdbdhdbhbhfadbeaegbbdce","habgbahaeebeacccbdhfhddegfebheeffdbcbgfahhgbhcheeb","gfaaedgcachcehgdghebbhegbfagdgcdcgebddbdccbedbbhcd","badaebdbdgeadbfgchaegaddgdhdgaeaaedagacgbdecfdghca","eefcceffcggeefbecaceadbdcfccgbfgffgahfgeebafdcfhhb","aeebdahabfecbafgbcchbhdeecaadaccbahghcbdcfaeagehha"};
    vector v2 = {38,36,23};
    
    int ans = s.minDeletionSize(v);
    cout << ans << endl;

    return 0;
}
