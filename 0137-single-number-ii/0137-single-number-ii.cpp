class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        int i=0;
        while(i<size){
            if(i==size-1){
                return nums[i];
            }
            if(nums[i]==nums[i+1]){
                i+=3;
            }else{
                return nums[i];
            }
        }
        return 0;
    }
};