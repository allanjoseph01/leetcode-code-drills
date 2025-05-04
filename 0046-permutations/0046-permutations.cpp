class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int siz=nums.size();
        if(siz==1){
            return;
        }
        int i;
        for(i=siz-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i<0){
            int k=0;
            int t=siz-1;
            while(k<t){
                int temp=nums[k];
                nums[k]=nums[t];
                nums[t]=temp;
                k++;
                t--;
            }
            return ;
        }
        int j;
        for(j=siz-1;j>i;j--){
            if(nums[j]>nums[i]){
                break;
            }
        }
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
        int k=i+1;
        int t=siz-1;
        while(k<t){
            int temp=nums[k];
            nums[k]=nums[t];
            nums[t]=temp;
            k++;
            t--;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int siz=nums.size();
        int p=1;
        int n=1;
        while(n<=siz){
            p*=n;
            n++;
        }
        while(p--){
            ans.push_back(nums);
            nextPermutation(nums);
        }
        // ans.push_back(nums);
        return ans;
    }
};