class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int siz=grid.size();
        int num=(siz*siz)-1;
        queue<pair<int,int>> q;
        for(int i=0;i<siz;i++){
            for(int j=0;j<siz;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    break;
                }
            }
            if(!q.empty()){
                break;
            }
        }
        vector<int> v1={1,-1,-2,-2,-1,1,2,2};
	    vector<int> v2={-2,-2,-1,1,2,2,1,-1};
        int cur=0;
	    while(!q.empty()){
	        pair<int,int> j=q.front();
	        q.pop();
            bool found=false;
            for(int k=0;k<8;k++){
	            if(j.first+v1[k]>=0 && j.first+v1[k]<siz && j.second+v2[k]>=0 && j.second+v2[k]<siz){
	                if(grid[j.first+v1[k]][j.second+v2[k]]==cur+1){
	                    q.push({j.first+v1[k],j.second+v2[k]});
                        cur++;
                        num--;
                        found=true;
                    }
	            }
	        }
            if(!found && num>0){
                return false;
            }
	    }
        return true;
    }
};