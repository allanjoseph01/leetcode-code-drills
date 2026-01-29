/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            if(q.front()->left!=nullptr){
                q.front()->left->next=q.front()->right;
                if(q.front()->next!=nullptr){
                    q.front()->right->next = q.front()->next->left;
                }
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        return root;
    }
};