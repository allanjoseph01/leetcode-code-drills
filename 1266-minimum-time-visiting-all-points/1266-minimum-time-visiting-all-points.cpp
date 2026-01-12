class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int siz=points.size();
        for(int i=1;i<siz;i++){
            int diffx = abs(points[i][0]-points[i-1][0]);      
            int diffy = abs(points[i][1]-points[i-1][1]);
            int mini=min(diffx,diffy);
            ans += (mini+(diffx-mini)+(diffy-mini));     
        }
        return ans;
    }
};