class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            while(nums[i]!=i+1){
                int ele=max(-10,nums[i]);
                int in=ele-1;
                if(in<0 || in>=siz){
                    break;
                }
                if(nums[i]==nums[in]){
                    break;
                }
                int t=nums[in];
                nums[in]=nums[i];
                nums[i]=t;
            }
        }
        for(int i=0;i<siz;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums[siz-1]+1;
    }
};