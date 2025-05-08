class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(prime[i]){
                for(int j=2;i*j<=right;j++){
                    prime[i*j]=false;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<=right;i++){
            if(prime[i] && i>=left && i<=right){
                ans.push_back(i);
            }
        }
        int siz=ans.size();
        if(siz<=1){
            return {-1,-1};
        }
        int n1=ans[0];
        int n2=ans[1];
        int diff=n2-n1;
        for(int i=1;i<siz;i++){
            if(diff>(ans[i]-ans[i-1])){
                n1=ans[i-1];
                n2=ans[i];
                diff=n2-n1;
            }
        }
        return {n1,n2};
    }
};