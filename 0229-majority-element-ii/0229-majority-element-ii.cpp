class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0;
        int m1=INT_MIN,m2=INT_MIN;

        int siz=nums.size();
        for(int i=0;i<siz;i++){
            if(c1==0 && m2!=nums[i]){
                m1=nums[i];
                c1++;
            }else if(c2==0 && m1!=nums[i]){
                m2=nums[i];
                c2++;
            }else if(m1==nums[i]){
                c1++;
            }else if(m2==nums[i]){
                c2++;
            }else{
                c1--;
                c2--;
            }
        }

        int p1=0,p2=0;
        for(int i=0;i<siz;i++){
            if(nums[i]==m1){
                p1++;
            }else if(nums[i]==m2){
                p2++;
            }
        }
        vector<int> ans;
        if(p1>(siz/3)){
            ans.push_back(m1);
        }
        if(p2>(siz/3)){
            ans.push_back(m2);
        }
        return ans;
    }
};