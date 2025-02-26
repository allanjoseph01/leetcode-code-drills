class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        vector<vector<int>> adj(n);
        int siz=edges.size();
        for(int i=0;i<siz;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<int> vis(n,-1);
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int s=adj[q.front()].size();
            // cout << q.front() << " ";
            for(int i=0;i<s;i++){
                if(vis[adj[q.front()][i]]==-1){
                    if(adj[q.front()][i]==destination){
                        return true;
                    }
                    vis[adj[q.front()][i]]=1;
                    q.push(adj[q.front()][i]);
                }
            }
            q.pop();
        }
        return false;
    }
};