class Solution {
public:
    void allpermute(int i,int n, vector<int>& nums,vector<vector<int>>& ans){
        if(i==n){
            ans.push_back(nums);
            return ;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            allpermute(i+1,n,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int siz=nums.size();
        vector<vector<int>> ans;
        allpermute(0,siz,nums,ans);
        return ans;
    }
};