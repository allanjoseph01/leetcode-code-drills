class Solution {
public:
    void alluniqueperm(int i,int n, vector<int>& arr,unordered_map<int,int>& mp , vector<vector<int>>& ans ){
        if(i==n){
            ans.push_back(arr);
            return ;
        }
        for(auto it : mp){
            if(it.second>0){
                arr.push_back(it.first);
                mp[it.first]--;
                alluniqueperm(i+1,n,arr,mp,ans);
                mp[it.first]++;
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int siz= nums.size();
        for(int i=0;i<siz;i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> ans;
        vector<int> temp;
        alluniqueperm(0,siz,temp , mp , ans);
        return ans;
    }
};