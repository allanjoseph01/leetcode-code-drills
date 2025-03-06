class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> top(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            top[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(top[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            count++;
            int num=q.front();
            q.pop();
            for(int i=0;i<adj[num].size();i++){
                top[adj[num][i]]--;
                if(top[adj[num][i]]==0){
                    q.push(adj[num][i]);
                }
            }
        }
        return count==numCourses;
    }
};