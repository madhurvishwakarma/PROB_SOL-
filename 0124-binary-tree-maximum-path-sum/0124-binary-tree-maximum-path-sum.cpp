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
public:
    int MaxSum( TreeNode* root , int& sum ){
        if( root == NULL ){
            return 0 ;
        }
        int lsum = max( 0 , MaxSum( root->left , sum ));
        int rsum = max( 0 , MaxSum( root->right , sum )) ;
        sum = max( sum , root->val + lsum + rsum ) ;
        return root->val + max( lsum , rsum ) ;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN ;// imp becuase "0" wala case would fail if negative num ka case aya 
        MaxSum( root , sum ) ;
        return sum ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna