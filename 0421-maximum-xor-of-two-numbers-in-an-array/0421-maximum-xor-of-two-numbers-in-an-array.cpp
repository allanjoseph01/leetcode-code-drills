class Node{
public:
    Node* bit[2];
    Node(){
        bit[0]=nullptr;
        bit[1]=nullptr;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int siz=nums.size();
        Node* root = new Node();
        for(int i=0;i<siz;i++){
            Node* temp = root;
            for(int j=31;j>=0;j--){ 
                int b=((nums[i]>>j)&1);
                if(temp->bit[b]==nullptr){
                    temp->bit[b]=new Node();
                }
                temp = temp->bit[b];
            }
        }
        int ans= INT_MIN;
        for(int i=0;i<siz;i++){
            int sam=0;
            Node* temp = root;
            for(int j=31;j>=0;j--){
                int b= ((nums[i]>>j)&1);
                if(temp->bit[1-b]!=nullptr){
                    temp = temp->bit[1-b];
                    sam= (sam|(1<<j));
                }else{
                    temp=temp->bit[b];
                }
            }
            ans=max(ans,sam);
        }
        return ans;
    }
};