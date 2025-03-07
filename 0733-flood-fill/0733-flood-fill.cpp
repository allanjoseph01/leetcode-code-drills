class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int num=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        vector<int> row={-1,0,0,1};
        vector<int> col={0,-1,1,0};
        vis[sr][sc]=1;
        image[sr][sc]=color;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                if(r+row[i]>=0 && r+row[i]<m && c+col[i]>=0 && c+col[i]<n){
                    if(vis[r+row[i]][c+col[i]]==-1 && image[r+row[i]][c+col[i]]==num){
                        image[r+row[i]][c+col[i]]=color;
                        vis[r+row[i]][c+col[i]]=1;
                        q.push({r+row[i],c+col[i]});
                    }
                }
            }
        }
        return image;
    }
};