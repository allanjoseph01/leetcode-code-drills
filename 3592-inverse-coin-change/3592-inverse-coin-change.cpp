class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int siz=numWays.size();
        vector<long long> arr(siz+1,0);
        arr[0]=1;
        vector<int> ans;
        for(int i=1;i<=siz;i++){
            if(arr[i]==numWays[i-1]){
                continue;
            }
            if(arr[i]+1<numWays[i-1] || arr[i]>numWays[i-1]){
                return {};
            }
            ans.push_back(i);
            for(int j=i;j<=siz;j++){
                arr[j]+=arr[j-i];
                // cout << arr[j] << " ";
            }
            // cout << endl;
        }
        return ans;
    }
};