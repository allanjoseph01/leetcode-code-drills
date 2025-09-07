class Solution {
public:
    bool wordSeg(int i,vector<int>& dp , string& s,unordered_set<string>& st){
        if(dp[i]==-1){
            int n= s.length();
            if(i==n){
                return true;
            }
            string str="";
            int found=0;
            for(int j=i;j<n;j++){
                str+=s[j];
                if(st.find(str)!=st.end()){
                    if(wordSeg(j+1,dp,s,st)){
                        found=1;
                    }
                }
            }
            dp[i]=found;
        }
        if(dp[i]==1){
            return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int siz=wordDict.size();
        unordered_set<string> st;
        for(int i=0;i<siz;i++){
            st.insert(wordDict[i]);
        }
        int n=s.length();
        vector<int> dp(n+1,-1);
        return wordSeg(0,dp,s,st);
    }
};