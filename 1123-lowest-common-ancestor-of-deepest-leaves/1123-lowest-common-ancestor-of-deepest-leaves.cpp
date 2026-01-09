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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){
            return root;
        }
        TreeNode* trev1=lowestCommonAncestor(root->left,p,q);
        TreeNode* trev2=lowestCommonAncestor(root->right,p,q);
        if(trev1!=nullptr && trev2!=nullptr){
            return root;
        }
        if(trev1==nullptr && trev2!=nullptr){
            return trev2;
        }
        if(trev2==nullptr && trev1!=nullptr){
            return trev1;
        }
        return nullptr;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        map<int,vector<TreeNode*>> mp;
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            int siz=q.size();
            bool next = false;
            for(int i=0;i<siz;i++){
                if(q.front()->right!=nullptr){
                    q.push(q.front()->right);
                    next = true;
                }
                if(q.front()->left!=nullptr){
                    q.push(q.front()->left);
                    next=true;
                }
                mp[depth].push_back(q.front());
                q.pop();
            }
            if(next){
                depth+=1;
            }
        }
        int siz=mp[depth].size();
        if(siz==1){
            return mp[depth][0];
        }
        TreeNode* allDeep = lowestCommonAncestor(root,mp[depth][0],mp[depth][1]);
        for(int i=2;i<siz;i++){
            allDeep = lowestCommonAncestor(root,allDeep,mp[depth][i]);
        }
        return allDeep;
    }
};