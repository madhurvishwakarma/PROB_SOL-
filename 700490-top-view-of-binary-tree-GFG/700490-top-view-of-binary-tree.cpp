/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> v ;
        if( root == NULL ){
            return v ;
        }
        map< int , int > mp ;
        queue<pair<Node*  , int >> q ;
        q.push({ root , 0 }) ;
        while( !q.empty() ){
            auto it = q.front() ;
            q.pop() ;
            Node* node = it.first ;
            int l = it.second ;
            if( mp.find(l) == mp.end()) mp[l] = node->data ;
            if( node->left ) q.push({node->left , l-1 }) ;
            if( node->right ) q.push({ node->right , l+1 }) ;
        }
        for( auto x : mp ){
            v.push_back( x.second ) ;
        }
        return v ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna