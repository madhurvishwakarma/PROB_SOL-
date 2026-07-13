/*
Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int find(Node* root , int& maxi ){
        if( root == NULL ){
            return 0 ;
        }
        int l = max( 0 , find(root->left , maxi)) ;
        int r = max( 0 , find(root->right , maxi )) ;
        maxi = max( maxi , root->data + l + r ) ;
        return root->data + max( l, r) ;
    }
    int findMaxSum(Node *root) {
        // code here
        int sum = INT_MIN ;
        find( root , sum ) ;
        return sum ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna