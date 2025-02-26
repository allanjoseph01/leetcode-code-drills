class Solution {
public:
    void dfs(int j,int k,vector<vector<char>>& lst){
        if(j<0 || j>=lst.size() || k<0 || k>=lst[0].size()){
            return ;
        }
        if(lst[j][k]=='0'){
            return ;
        }
        lst[j][k]='0';
        dfs(j+1,k,lst);
        dfs(j,k+1,lst);
        dfs(j-1,k,lst);
        dfs(j,k-1,lst);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};