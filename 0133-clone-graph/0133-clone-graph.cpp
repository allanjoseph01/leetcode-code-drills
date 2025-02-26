/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        Node* head = new Node(node->val);
        queue<Node* > q;
        q.push(node);
        map<Node*,Node*> mp;
        mp[node]=head;
        while(!q.empty()){
            Node* temp = mp[q.front()];
            int s=q.front()->neighbors.size();
            for(int i=0;i<s;i++){
                if(mp.find(q.front()->neighbors[i])==mp.end()){
                    Node* trev=new Node(q.front()->neighbors[i]->val);
                    mp[q.front()->neighbors[i]]=trev;
                    q.push(q.front()->neighbors[i]);       
                }
                temp->neighbors.push_back(mp[q.front()->neighbors[i]]);
            }
            q.pop();
        }
        return head;
    }
};