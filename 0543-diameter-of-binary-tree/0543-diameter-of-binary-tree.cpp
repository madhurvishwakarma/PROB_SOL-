/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public :
    int height( TreeNode* root , int& maxi ){
        if( root == NULL ){
            return 0 ;
        }
        int l = height( root->left , maxi) ;
        int r = height( root->right , maxi ) ;
        maxi = max( maxi, l+r) ;
        return 1+ max( r , l ) ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
      int len = 0 ;
      height( root , len ) ;
      return len ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna