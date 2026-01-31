class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int siz=letters.size();
        int l=0,h=siz-1;
        int ans=0;
        while(l<=h){
            int m=((l+h)/2);
            if(int(letters[m])>int(target)){
                ans = m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return letters[ans];
    }
};