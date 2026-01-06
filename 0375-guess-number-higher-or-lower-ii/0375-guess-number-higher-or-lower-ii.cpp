class Solution {
public:
    int game(vector<vector<int>>& dp,int m, int n){
        if(dp[m][n]==-1){
            if(m==n){
                dp[m][n]=0;
            }else{
                int round = m+game(dp,m+1,n);
                for(int l=m+1;l<n;l++){
                    int step = l + max(game(dp,m,l-1),game(dp,l+1,n));
                    round= min(round,step);
                }
                round= min(round,n+game(dp,m,n-1));
                dp[m][n]=round;
            }
        }
        return dp[m][n];
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return game(dp,1,n);
    }
};