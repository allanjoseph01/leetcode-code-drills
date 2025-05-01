class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> ans(4,true);
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(target[i][j]!=mat[i][j]){
                    ans[0]=false;
                }
                if(target[i][j]!=mat[n-1-i][n-1-j]){
                    ans[1]=false;
                }
                if(target[i][j]!=mat[i][n-1-j]){
                    ans[2]=false;
                }
                if(target[i][j]!=mat[n-1-i][j]){
                    ans[3]=false;
                }
                if(!ans[0] && !ans[1] && !ans[2] && !ans[3]){
                    return false;
                }
            }
        }
        return true;
    }
};