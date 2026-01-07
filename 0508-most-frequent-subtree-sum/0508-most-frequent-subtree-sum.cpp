/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int> mp;
    int maxfreq = INT_MIN;
    int sumCalculate(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            mp[root->val]+=1;
            maxfreq = max(maxfreq,mp[root->val]);
            return root->val;
        }
        int s= root->val + sumCalculate(root->left) + sumCalculate(root->right);
        mp[s]+=1;
        maxfreq = max(maxfreq,mp[s]);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sumCalculate(root);
        vector<int> ans;
        for(auto i : mp){
            if(i.second == maxfreq){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};