class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            while(nums[i]!=i+1){
                int ele=nums[i];
                int in=ele-1;
                if(in<0 || in>=siz){
                    break;
                }
                if(nums[i]==nums[in]){
                    return nums[i];
                }
                int t=nums[in];
                nums[in]=nums[i];
                nums[i]=t;
            }
        }
        return siz;
    }
};