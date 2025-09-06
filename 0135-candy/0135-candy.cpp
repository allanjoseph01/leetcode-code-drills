class Solution {
public:
    int candy(vector<int>& ratings) {
        int siz=ratings.size();
        vector<int> chocos(siz,1);
        for(int i=1;i<siz;i++){
            if(ratings[i]>ratings[i-1]){
                chocos[i] = chocos[i-1]+1;
            }
        }
        for(int j=siz-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]){
                chocos[j] = max(chocos[j],chocos[j+1]+1);
            }
        }
        int sum=0;
        for(int i=0;i<siz;i++){
            sum+=chocos[i];
        }
        return sum;
    }
};