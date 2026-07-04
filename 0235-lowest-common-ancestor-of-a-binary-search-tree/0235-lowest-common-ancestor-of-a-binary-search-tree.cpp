/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == NULL || p == root || q == root ){
            return root ;
        }
        if( (p->val > root->val && q->val < root->val) || (p->val < root->val && q->val > root->val) ){
            return root ;
        }
        TreeNode* left = lowestCommonAncestor( root->left , p , q ) ;
        TreeNode* right = lowestCommonAncestor( root->right , p , q ) ;
        if( right == NULL ) return left ;
        else if( left == NULL ) return right ;
        else return root ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna