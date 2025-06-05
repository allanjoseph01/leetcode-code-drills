class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int i=0;
        int j=-1;
        int siz=nums.size();
        int ans=INT_MAX;
        while(j<siz){
            if(sum<target){
                j++;
                if(j==siz){
                    break;
                }
                sum+=nums[j];
            }else{
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};