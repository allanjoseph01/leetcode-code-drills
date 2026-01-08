class Solution {
public:

    int maxSum(vector<int>& arr1, vector<int>& arr2, int i,int j , vector<vector<int>>& dp,int s1,int s2){
        if(i>=s1 || j>=s2){
            return INT_MIN;
        }
        if(dp[i][j]==INT_MIN){
            int temp = INT_MIN;
            for(int l=j;l<s2;l++){
                int next = maxSum(arr1, arr2, i+1, l+1, dp, s1, s2);
                int prod = arr1[i] * arr2[l];
                temp = max(temp, prod);
                if(next != INT_MIN){
                    temp = max(temp, prod + next);
                }
            }
            temp=max(temp,maxSum(arr1,arr2,i+1,j,dp,s1,s2));
            dp[i][j]=temp;
        }
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int siz1=nums1.size();
        int siz2=nums2.size();
        vector<vector<int>> dp(siz1,vector<int> (siz2,INT_MIN));
        return maxSum(nums1, nums2, 0,0,dp,siz1,siz2);
    }
};