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
        if(!node){return NULL;}
        queue<Node*> q;
        Node* root=new Node(node->val);
        q.push(node);
        map<Node*, Node*> mp;
        mp[node] = root;
        while(!q.empty()){
            auto t = q.front();q.pop();
            for(auto a:t->neighbors){
                Node* temp;
                if(mp.find(a) == mp.end()){
                    temp = new Node(a->val);
                    q.push(a);
                    mp[a] = temp;
                }
                temp = mp[a];
                mp[t]->neighbors.push_back(temp);
            }
        }
        return root;
    }
};