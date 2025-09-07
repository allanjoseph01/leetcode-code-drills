class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<long long>> dp(k+1, vector<long long>(n+1, 0));

        int m = 0; // moves
        while (dp[k][m] < n) {
            m++;
            for (int e = 1; e <= k; e++) {
                dp[e][m] = dp[e-1][m-1] + dp[e][m-1] + 1;
            }
        }
        return m;
    }
};