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
    bool same( TreeNode* root , TreeNode* node ){
        if( root == NULL && node == NULL ){
            return true ;
        }
        if( root == NULL || node == NULL ){
            return false ;
        }
        if( root->val != node->val ){
            return false ;
        }
        return same( root->left , node->right ) && same( root->right , node->left ) ;
    }
    bool isSymmetric(TreeNode* root) {
        return same( root->left , root->right ) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna