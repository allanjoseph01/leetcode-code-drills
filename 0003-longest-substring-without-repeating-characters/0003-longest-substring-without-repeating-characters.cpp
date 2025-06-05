class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=-1;
        int siz=s.length();
        int ans=0;
        unordered_map<char,int> mp;
        while(j<siz){
            if(j-i+1 == mp.size()){
                ans=max(ans,j-i+1);
                j++;
                if(j==siz){
                    break;
                }
                mp[s[j]]++;
            }else{
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};