/* Structure of a Tree Node
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
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if( root == NULL ) return true ;
        if (root->left == NULL && root->right == NULL)  return true;
        int left = 0 ,right = 0 ;
        if( root->left ) left = root->left->data ;
        if( root->right ) right = root->right->data ;
        if( root->data != left + right ) return false ;
        return isSumProperty( root->left ) && isSumProperty( root->right ) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna