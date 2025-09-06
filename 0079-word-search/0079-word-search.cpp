class Solution {
public:
    bool wordexist(int i,int j , int m,int n , vector<vector<char>>& board, string word, int index){
        if(index==word.length()){
            return true;
        }
        if(i<0 || i >=m || j<0 || j>=n || board[i][j]!=word[index]){
            return false;
        }
        char ch= board[i][j];
        board[i][j]='#';
        bool found = wordexist(i+1,j,m,n,board,word,index+1) || wordexist(i-1,j,m,n,board,word,index+1) || wordexist(i,j+1,m,n,board,word,index+1) || wordexist(i,j-1,m,n,board,word,index+1);
        board[i][j]= ch;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(wordexist(i,j,m,n,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};