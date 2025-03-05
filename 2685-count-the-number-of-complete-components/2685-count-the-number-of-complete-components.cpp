class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj, vector<int>& poh,int& ver,int& ed){
        poh[node]=1;
        ver++;
        for(int i=0;i<adj[node].size();i++){
            ed--;
            if(poh[adj[node][i]]==-1){
                dfs(adj[node][i],adj,poh,ver,ed);
            }
        }
        return ;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,-1);
        vector<vector<int>> edge(n);
        int e=edges.size();
        for(int i=0;i<e;i++){
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                int no=0;
                int prev=e;
                dfs(i,edge,vis,no,e);
                int after=e;
                int total=(prev-after)/2;
                e+=total;
                if(total==((no*(no-1))/2)){
                    count++;
                }
            }
        }
        return count;
    }
};