class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> cnt(strs.size(), vector<int>(2));

        // cnt the one and zero
        for(int i = 0 ; i < strs.size() ; i++) {

            cnt[i][0] = count(strs[i].begin(), strs[i].end(), '0');
            cnt[i][1] = count(strs[i].begin(), strs[i].end(), '1');
        }

        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        int index = 0;

        // we will fill the dp through all cases of input
        // dp[i][j] = max(1+dp[i-zero][j-one], dp[i][j])

        // dp[i][j] means the optimal(largest subset of strs) solution at m = i amd n = j
        for(int k = 0 ; k < cnt.size() ; k++) {

            // fill the table
            for(int i = m ; i >= 0 ; i--) {
            
                for(int j = n ; j >= 0 ; j--) {

                    if(i-cnt[k][0] >= 0 && j-cnt[k][1] >= 0) {
                        
                        dp[i][j] = max(1+dp[i-cnt[k][0]][j-cnt[k][1]], dp[i][j]);
                    }
                    else
                        break;
                }
            }
        }
        return dp[m][n];
    }
};