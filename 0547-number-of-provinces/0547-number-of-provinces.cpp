class Solution {
public:
    int count=0;
    void dfs(int num,vector<vector<int>>& lst,vector<int>& visi){
        visi[num]=1;
        for(int i=0;i<lst[num].size();i++){
            if(visi[lst[num][i]]==-1){
                dfs(lst[num][i],lst,visi);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                count++;
                dfs(i,arr,vis);
            }
        }
        return count;
    }
};