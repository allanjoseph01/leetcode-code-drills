class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=0;
        while(!q.empty()){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                if((q.front().first-1) >=0){
                    if(grid[q.front().first-1][q.front().second]==1){
                        grid[q.front().first-1][q.front().second]=2;
                        q.push({q.front().first-1,q.front().second});
                    }
                }
                if((q.front().first+1)<m){
                    if(grid[q.front().first+1][q.front().second]==1){
                        grid[q.front().first+1][q.front().second]=2;
                        q.push({q.front().first+1,q.front().second});
                    }
                }
                if((q.front().second-1)>=0){
                    if(grid[q.front().first][q.front().second-1]==1){
                        grid[q.front().first][q.front().second-1]=2;
                        q.push({q.front().first,q.front().second-1});
                    }
                }
                if((q.front().second+1)<n){
                    if(grid[q.front().first][q.front().second+1]==1){
                        grid[q.front().first][q.front().second+1]=2;
                        q.push({q.front().first,q.front().second+1});
                    }
                }
                q.pop();
            }
            count++;
            if(q.empty()){
                count--;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }
};