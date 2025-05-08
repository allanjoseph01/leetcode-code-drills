class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=2;i*j<=n;j++){
                    prime[i*j]=false;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<=n;i++){
            if(prime[i] && prime[n-i]){
                ans.push_back({i,n-i});
                prime[i]=false;
            }
        }
        return ans;
    }
};