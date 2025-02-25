class Solution {
public:
    int dp(string& s1,string& s2,vector<vector<int>>& lst,int i1,int i2){
        if(i1<0){
            int temp=0;
            for(int i=0;i<=i2;i++){
                temp+=int(s2[i]);
            }
            return temp;
        }
        if(i2<0){
            int temp=0;
            for(int i=0;i<=i1;i++){
                temp+=int(s1[i]);
            }
            return temp;
        }
        if(lst[i1][i2]==-1){
            if(s1[i1]==s2[i2]){
                lst[i1][i2]=dp(s1,s2,lst,i1-1,i2-1);
            }else{
                lst[i1][i2]=min(dp(s1,s2,lst,i1,i2-1)+int(s2[i2]),int(s1[i1])+dp(s1,s2,lst,i1-1,i2));
            }
        }
        return lst[i1][i2];
    }
    int minimumDeleteSum(string s1, string s2) {
        int siz1=s1.size();
        int siz2=s2.size();
        vector<vector<int>> arr(siz1,vector<int> (siz2,-1));
        vector<int> in1(siz1,0);
        vector<int> in2(siz2,0);
        return dp(s1,s2,arr,siz1-1,siz2-1);
    }
};