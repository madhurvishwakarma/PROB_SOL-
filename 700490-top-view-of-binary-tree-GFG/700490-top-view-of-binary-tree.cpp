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
        map<int,int> mp ;
        queue<pair<Node*,int>> q ;
        q.push({root , 0 }) ;
        while( !q.empty()){
            Node* node = q.front().first ;
            int index = q.front().second ;
            q.pop() ;
            if( mp.find(index) == mp.end()) mp[index] = node->data ;
            if( node->left ) q.push({node->left , index-1}) ;
            if( node->right ) q.push({node->right , index+1}) ;
        }
        for(auto it : mp ){
            v.push_back(it.second) ;
        }
        return v ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna