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
    unordered_map<int, Node*> ourmap;
    Node *clone(Node *node){
        if(ourmap.find(node->val)!=ourmap.end())
            return ourmap[node->val];
        
        Node *newnode=new Node(node->val);
        ourmap[node->val]=newnode;
        for(Node* neighbor:node->neighbors){
            newnode->neighbors.push_back(clone(neighbor));
        }
        return newnode;
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        return clone(node);
    }
};