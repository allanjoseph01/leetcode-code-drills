class Solution {
public:
    int m,n;
    void dfs(vector<vector<char>>& mat,int r,int c,char dir){
        mat[r][c]='.';
        if(dir=='h'){
            if(c+1<n && mat[r][c+1]=='X'){
                dfs(mat,r,c+1,'h');
            }
        }else if(dir=='v'){
            if(r+1<m && mat[r+1][c]=='X'){
                dfs(mat,r+1,c,'v');
            }
        }else{
            if(c+1<n && mat[r][c+1]=='X'){
                dfs(mat,r,c+1,'h');
            }else if(r+1<m && mat[r+1][c]=='X'){
                dfs(mat,r+1,c,'v');
            }
        }
        return ;
    }
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    dfs(board,i,j,'c');
                    count++;
                }
            }
        }
        return count;
    }
};