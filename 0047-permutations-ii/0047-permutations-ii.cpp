class Solution {
public:
    vector<vector<int>> ans;
    void unique(vector<int>& nums , int index){
        int s=nums.size();
        if(index==s){
            ans.push_back(nums);
            return ;
        }
        unordered_set<int> st;
        for(int i=index;i<s;i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                swap(nums[i], nums[index]);
                unique(nums,index+1);
                swap(nums[i], nums[index]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unique(nums,0);
        return ans;
    }
};