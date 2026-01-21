class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int siz=nums.size();
        vector<int> ans(siz,-1);
        for(int i=0;i<siz;i++){
            if(nums[i]!=2){
                int pos=0;
                int n= nums[i];
                while(((n>>pos)&1)==1){
                    pos++;
                }
                ans[i] = n & ~((1<<(pos-1)));
            }
        }
        return ans;
    }
};