/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* pre( Node* root , int& key ){
        Node* p = NULL ;
        while( root ){
          if( key > root->data ){
            p = root ;
            root = root->right ;
        }
        else{
            root = root->left ;
        }  
        }
        return p ;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* s = NULL ;
        Node* p = pre(root,key) ;
        while(root){if( key >= root->data ){
            root = root->right ;
        }
        else{
            s = root ;
            root = root->left ;
        }}
        return {p, s} ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna