class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int siz=nums.size();
        int i=1;
        bool first = false;
        while(i<siz){
            if(nums[i]>nums[i-1]){
                first = true;
                i++;
            }else{
                break;
            }
        }
        bool second = false;
        if(first){
            while(i<siz){
                if(nums[i]<nums[i-1]){
                    second = true;
                    i++;
                }else{
                    break;
                }
            }
        }
        if(second){
            if(i<siz){
                while(i<siz){
                    if(nums[i]>nums[i-1]){
                        i++;
                    }else{
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        return false;
    }
};