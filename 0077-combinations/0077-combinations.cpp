class Solution {
public:
    void allcomb(int i,int n, int j,int k,vector<int>& arr, vector<vector<int>>& ans){
        if(j==k){
            ans.push_back(arr);
            return ;
        }
        for(int l=i;l<=n;l++){
            arr.push_back(l);
            allcomb(l+1,n,j+1,k,arr,ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        allcomb(1,n,0,k,arr,ans);
        return ans;
    }
};