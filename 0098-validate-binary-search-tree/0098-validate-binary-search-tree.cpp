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
    bool check( TreeNode*& root , long long lo , long long hi ){
        if( root == NULL ){
            return true ;
        }
        if( root->val >= hi || root->val <= lo ){
            return false ;
        }
        return check( root->left , lo , root->val ) && check( root->right , root->val , hi ) ;
    }
    bool isValidBST(TreeNode* root) {
        return check( root , LLONG_MIN , LLONG_MAX ) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna