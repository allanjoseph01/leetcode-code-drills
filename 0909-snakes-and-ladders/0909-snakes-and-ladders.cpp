class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int N=(n*n)+1;
        vector<int> value(N,-1);
        int index=1;
        for(int i=n-1,row=0;i>=0;i--,row++){
            if(row%2==0){ 
                for(int j=0;j<n;j++){
                    if(board[i][j]!=-1){
                        value[index]=board[i][j];
                    }
                    index++;
                }
            }else{
                for(int j=n-1;j>=0;j--){
                    if(board[i][j]!=-1){
                        value[index]=board[i][j];
                    }
                    index++;
                }
            }
        }
        vector<int> vis(N,0);
        queue<int> q;
        vis[1]=1;
        q.push(1);
        int step=0;
        while(!q.empty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                int num=q.front();
                if(num==N-1){
                    return step;
                }
                q.pop();
                for(int i=1;i<=6;i++){
                    if(num+i>=N){
                        continue;
                    }
                    int next=num+i;
                    if(value[num+i]!=-1){
                        next=value[next];
                    }
                    if(vis[next]==0){
                        vis[next]=1;
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};