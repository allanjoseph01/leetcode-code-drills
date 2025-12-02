class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set<int> st;
        int i=0,j=1;
        int ans = INT_MAX;
        st.insert(cards[0]);
        int siz=cards.size();
        while(j<siz){
            if(st.find(cards[j])!=st.end()){
                while(cards[i]!=cards[j]){
                    st.erase(cards[i]);
                    i++;
                }
                ans=min(ans,(j-i+1));
                i++;
            }else{
                st.insert(cards[j]);
            }
            j++;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};