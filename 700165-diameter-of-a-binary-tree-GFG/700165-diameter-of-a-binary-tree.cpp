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
    int find( Node* root , int& maxi ){
        if( root == NULL ){
            return 0 ;
        }
        int lh = max(0,find(root->left,maxi)) ;
        int rh = max(0,find(root->right , maxi)) ;
        maxi = max( maxi , lh+rh) ;
        return 1+max(lh,rh) ;
    }
    int diameter(Node* root) {
        // code here
        int maxi= 0 ;
        find( root , maxi ) ;
        return maxi ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna