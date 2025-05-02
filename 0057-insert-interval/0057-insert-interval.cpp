class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(),intervals.end());
        int s1=intervals.size();
        int j=0;
        int s=-1;
        int e=-1;
        vector<vector<int>> ans;
        for(int i=0;i<s1;i++){
            if(s==-1 && e==-1){
                s=intervals[i][0];
                e=intervals[i][1];
            }
            if((newInterval[0]>=s && newInterval[0]<=e) || (newInterval[1]>=s && newInterval[1]<=e) || (s>=newInterval[0] && s<=newInterval[1]) || (e>=newInterval[0] && e<=newInterval[1])){
                s=min(s,newInterval[0]);
                e=max(e,newInterval[1]);
                j++;
            }
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
        if(s!=-1 && e!=-1){
            vector<int> a(2);
            a[0]=s;
            a[1]=e;
            ans.push_back(a);
        }
        if(j==0){
            ans.push_back(newInterval);
        }
        return ans;
    }
};