class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int i=0,j=1;
        long long ans = INT_MIN;
        long long sum = nums[0];
        st.insert(nums[0]);
        int siz=nums.size();
        while(j<siz){
            if(st.find(nums[j])!=st.end()){
                ans=max(ans,sum);
                while(nums[i]!=nums[j]){
                    sum-=nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                i++;
            }else{
                st.insert(nums[j]);
                sum+=nums[j];
            }
            j++;
        }
        ans=max(ans,sum);
        return ans;
    }
};