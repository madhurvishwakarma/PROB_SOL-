/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isLeaf( Node* root ){
        return root != NULL && root->left == NULL && root->right == NULL ;
    }
    void goLeft( Node* root , vector<int>& left ){
        if( root == NULL ){
            return ;
        }
        Node* node = root->left ;
        while( node != NULL ){
            if( !isLeaf(node) ){
                left.push_back(node->data) ;
            }
            if( node->left ){
                node = node->left ;
            }
            else{
                node = node->right ;
            }
        }
    }
    void goRight( Node* root , vector<int>& right ){
        if( root == NULL ){
            return ;
        }
        Node* node = root->right ;
        vector<int> v ;
        while( node != NULL ){
            if( !isLeaf(node) ){
                v.push_back( node->data ) ;
            }
            if( node->right ){
                node = node->right ;
            }
            else{
                node = node->left ;
            }
        }
        for( int i = v.size()-1 ; i >= 0 ; i-- ){
            right.push_back(v[i]) ;
        }
    }
    void Leaves( Node* root , vector<int>& leaf ){
        if( root == NULL ){
            return ;
        }
        if( isLeaf(root)){
            leaf.push_back(root->data) ;
            return ;
        }
        if( root->left ) Leaves( root->left , leaf ) ;
        if( root->right) Leaves( root->right , leaf ) ;
    }
    vector<int> boundaryTraversal(Node *root) {

    vector<int> v;

    if (root == NULL)
        return v;

    if (!isLeaf(root))
        v.push_back(root->data);

    goLeft(root, v);
    Leaves(root, v);
    goRight(root, v);

    return v;
}
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna