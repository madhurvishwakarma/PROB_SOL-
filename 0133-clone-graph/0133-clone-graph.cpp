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
        if( node == NULL ) return NULL ;
        Node* clone = new Node(node->val) ;
        unordered_map<Node* , Node*> vis ;
        vis[node] = clone ;
        queue<Node*> q ;
        q.push(node) ;
        while( !q.empty() ){
            Node* curr = q.front() ;
            q.pop() ;
            for( Node* x : curr->neighbors ){
                if( vis.count(x) == 0 ){
                    vis[x] = new Node(x->val) ;
                    q.push(x) ;
                }
                vis[curr]->neighbors.push_back(vis[x]) ;
            }
        }
        return clone ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna