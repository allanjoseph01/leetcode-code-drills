class Solution {
public:
    int dfs(int j,int k,vector<vector<int>>& lst){
        if(j<0 || j>=lst.size() || k<0 || k>=lst[0].size()){
            return 0;
        }
        if(lst[j][k]==0){
            return 0;
        }
        lst[j][k]=0;
        return 1+dfs(j+1,k,lst)+dfs(j,k+1,lst)+dfs(j-1,k,lst)+dfs(j,k-1,lst);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return max(ans,0);
    }
};