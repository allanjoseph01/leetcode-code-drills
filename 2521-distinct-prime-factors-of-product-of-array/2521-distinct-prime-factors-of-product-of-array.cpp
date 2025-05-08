class Solution {
public:
    unordered_set<int> primes;
    void fact(int prod){
        vector<bool> prime(prod+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<=prod;i++){
            if(prime[i]){
                bool co=false;
                while(prod%i==0){
                    prod/=i;
                    co=true;
                }
                if(co){
                    primes.insert(i);
                }
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        long long prod=1;
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            fact(nums[i]);
        }
        return primes.size();
    }
};