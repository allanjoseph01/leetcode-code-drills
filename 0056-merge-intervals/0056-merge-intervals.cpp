class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int siz=intervals.size();
        sort(intervals.begin(),intervals.end());
        int s=-1;
        int e=-1;
        for(int i=0;i<siz;i++){
            if(s==-1 && e==-1){
                s=intervals[i][0];
                e=intervals[i][1];
            }else{
                if((intervals[i][0]>=s && intervals[i][0]<=e) || (intervals[i][1]>=s && intervals[i][1]<=e)){
                    s=min(s,intervals[i][0]);
                    e=max(e,intervals[i][1]);
                }else{
                    vector<int> a(2);
                    a[0]=s;
                    a[1]=e;
                    ans.push_back(a);
                    s=-1;
                    e=-1;
                    i--;
                }
            }
        }
        if(s!=-1 && e!=-1){
            vector<int> a(2);
            a[0]=s;
            a[1]=e;
            ans.push_back(a);
        }
        return ans;  
    }
};