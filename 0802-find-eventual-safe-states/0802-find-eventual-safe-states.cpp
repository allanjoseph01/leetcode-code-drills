class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int siz=graph.size();
        vector<vector<int>> back(siz);
        vector<int> top(siz);
        queue<int> q;
        for(int i=0;i<siz;i++){
            int s=graph[i].size();
            for(int j=0;j<s;j++){
                back[graph[i][j]].push_back(i);
            }
            top[i]=s;
            if(s==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            int num=q.front();
            q.pop();
            for(int i=0;i<back[num].size();i++){
                if(--top[back[num][i]]==0){
                    q.push(back[num][i]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};