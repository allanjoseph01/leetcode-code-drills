class Solution {
public:
    int dp(int n,int i,vector<int>& org,vector<int>& dpa){
        if(i>=n){
            return 0;
        }
        if(dpa[i]==-1){
            dpa[i]=max(dp(n,i+1,org,dpa),org[i]+dp(n,i+2,org,dpa));
        }
        return dpa[i];
    }
    int rob(vector<int>& nums) {
        int siz=nums.size();
        if(siz==1) return nums[0];
        vector<int> arr1(siz-1,-1);
        vector<int> arr2(siz-1,-1);
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        int case1=dp(siz-1,0,nums1,arr1);
        int case2=dp(siz-1,0,nums2,arr2);
        return max(case1,case2);
    }
};