class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int teve=0;
        int todd=0;
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            if(i%2==0){
                teve+=nums[i];
            }else{
                todd+=nums[i];
            }
        }
        int leve=0;
        int lodd=0;
        int c=0;
        for(int i=0;i<siz;i++){
            if(i%2==0){
                if((leve+todd)==(lodd+teve-nums[i])){
                    c++;
                }
                leve+=nums[i];
                teve-=nums[i];
            }else{
                if((lodd+teve)==(todd+leve-nums[i])){
                    c++;
                }
                lodd+=nums[i];
                todd-=nums[i];
            }
        }
        return c;
    }
};