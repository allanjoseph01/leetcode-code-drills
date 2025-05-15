class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo=0;
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            xo^=nums[i];
        }
        int bit=0;
        while(!((xo>>bit)&1)){
            bit++;
        }
        int f=0,s=0;
        for(int i=0;i<siz;i++){
            if((nums[i]>>bit)&1){
                f^=nums[i];
            }else{
                s^=nums[i];
            }
        }
        if(f>s){
            return {s,f};
        }
        return {f,s};
    }
};