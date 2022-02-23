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
     Node* clone(Node* node,vector<Node*>& visited) {
         if(!visited[node->val]){
          Node* nm = new Node(node->val);
          visited[node->val] = nm;
          int n = (node->neighbors).size();
           for(int i=0;i<n;i++){
             (nm->neighbors).push_back(clone(node->neighbors[i],visited)); 
           }
         }
         return visited[node->val]; 
     }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        vector<Node*>v(101,NULL);
        return clone(node,v);
    }
};