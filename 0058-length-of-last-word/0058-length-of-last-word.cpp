class Solution {
public:
    int lengthOfLastWord(string s) {
        int length= 0;
        int siz=s.length();
        bool newWord = true;
        for(int i=0;i<siz;i++){
            if(s[i]!=' '){
                if(newWord){
                    length = 1;
                    newWord = false;
                }else{
                    length+=1;
                }
            }else{
                newWord = true;
            }
        }
        return length;
    }
};