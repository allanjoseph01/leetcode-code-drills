class Solution {
public:
    vector<vector<int>> ans;
    void combination(int kr, int n, int cs,vector<int>& as,int sc){
        if(kr==0 && cs==n){
            ans.push_back(as);
            return ;
        }else if(cs>n){
            return ;
        }else if(kr==0){
            return ;
        }
        for(int i=sc;i<=9;i++){
            as.push_back(i);
            combination(kr-1,n,cs+i,as,i+1);
            as.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        combination(k,n,0,temp,1);
        return ans;
    }
};