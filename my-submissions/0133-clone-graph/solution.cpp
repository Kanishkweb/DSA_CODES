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
    unordered_map<Node*, Node*> mp;
    void DFS(Node* node,Node*clone_node){
        for(Node*n :node->neighbors){
            if(mp.find(n) == mp.end()){
                Node* nn = new Node(n->val);
                mp[n] = nn;
                clone_node->neighbors.push_back(mp[n]);
                DFS(n,nn);
            } else{
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        // cloned the given node
        Node* clone_node = new Node(node->val);
        // Now clone its neighbour and recursively its neighbours
        // but is a node reappear then we need to access the node
        mp[node] = clone_node;
        DFS(node,clone_node);
        return clone_node;
    }
};
