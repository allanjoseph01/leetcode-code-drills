class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second>b.second;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        int siz=times.size();
        for(int i=0;i<siz;i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>>, Compare> pq;
        vector<int> mt(n+1,INT_MAX);
        mt[k]=0;
        pq.push({k,0});
        while(!pq.empty()){
            int index=pq.top().first;
            int tim=pq.top().second;
            pq.pop();
            if(tim>mt[index]){
                continue;
            }
            int s=adj[index].size();
            for(int i=0;i<s;i++){
                int nexs=adj[index][i].first;
                int tims=adj[index][i].second;
                if((tim+tims)<mt[nexs]){
                    mt[nexs]=tim+tims;
                    pq.push({nexs,mt[nexs]});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(mt[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,mt[i]);
        }
        return ans;
    }
};