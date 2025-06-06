class Solution {
public:
    string minWindow(string s, string t) {
        int mps[128] = {0};
        int mpt[128] = {0};
        int sizt=t.length();
        int sizs=s.length();
        for(int i=0;i<sizt;i++){
            mpt[t[i]]++;
        }
        int i=0,j=-1;
        int match=0;
        int ans=INT_MAX;
        int start=0;
        while(j<sizs){
            if(match==sizt){
                if(ans>(j-i+1)){
                    ans=j-i+1;
                    start=i;
                }
                mps[s[i]]--;
                if(mps[s[i]]<mpt[s[i]]){
                    match--;
                }
                i++;
            }else{
                j++;
                if(j==sizs){
                    break;
                }
                mps[s[j]]++;
                if(mps[s[j]]<=mpt[s[j]]){
                    match++;
                }
            }
        }
        if(ans==INT_MAX){
            ans=0;
        }
        return s.substr(start,ans);
    }
};