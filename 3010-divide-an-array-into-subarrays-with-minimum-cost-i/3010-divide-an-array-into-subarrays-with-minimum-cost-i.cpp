class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int siz=nums.size();
        int ans = nums[0];
        int min1=51,min2=52;
        for(int i=1;i<siz;i++){
            if(nums[i]<=min1){
                min2=min1;
                min1=nums[i];
            }else if(nums[i]>min1 && nums[i]<min2){
                min2=nums[i];
            }
        }
        return ans+min1+min2;
    }
};