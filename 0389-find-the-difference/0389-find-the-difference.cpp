class Solution {
public:
    char findTheDifference(string s, string t) {
        int s1=s.length();
        int s2=s1+1;
        int ans=0;
        for(int i=0;i<s1;i++){
            ans^=s[i];
        }
        for(int i=0;i<s2;i++){
            ans^=t[i];
        }
        return char(ans);
    }
};