class Solution {
public:
    int dp(string& s1,string& s2,vector<vector<int>>& lst,int i1,int i2){
        if(i1<0 || i2<0){
            return 0;
        }
        if(lst[i1][i2]==-1){
            if(s1[i1]==s2[i2]){
                lst[i1][i2]=dp(s1,s2,lst,i1-1,i2-1)+1;
            }else{
                lst[i1][i2]=max(dp(s1,s2,lst,i1,i2-1),dp(s1,s2,lst,i1-1,i2));
            }
        }
        return lst[i1][i2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int siz1=text1.size();
        int siz2=text2.size();
        vector<vector<int>> arr(siz1,vector<int> (siz2,-1));
        return dp(text1,text2,arr,siz1-1,siz2-1);
    }
};