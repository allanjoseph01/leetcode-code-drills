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
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        while(k-->1){
            nextPermutation(nums);
        }
        string ans="";
        for(int i=0;i<n;i++){
            ans+=to_string(nums[i]);
        }
        return ans;
    }
};