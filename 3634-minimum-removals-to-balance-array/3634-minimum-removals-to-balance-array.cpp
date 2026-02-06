class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int siz=nums.size();
        int ans = INT_MAX;
        int low,high,sm,bg;
        long long limit;
        for(int i=0;i<siz;i++){
            sm = i;
            // limit = (long long)(nums[i]*k);
            limit = 1LL * nums[i] * k;
            low = i;
            high = siz-1;
            int m;
            while(low<=high){
                m = ((low+high)/2);
                if(nums[m]<=limit){
                    bg=m;
                    low=m+1;
                }else{
                    high=m-1;
                }
            }
            ans = min(ans,(sm+((siz-1)-bg)));
        }
        return ans;
    }
};