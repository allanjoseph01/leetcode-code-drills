class Solution {
public:
    int maxArea(vector<int>& height) {
        int siz=height.size();
        int p1=0;
        int p2=siz-1;
        int ans=0;
        while(p1<p2){
            int w = p2-p1;
            int h= min(height[p1],height[p2]);
            ans=max(ans,(w*h));
            if(height[p1]<height[p2]){
                p1++;
            }else{
                p2--;
            }
        }
        return ans;
    }
};