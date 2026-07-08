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
    TreeNode* give( TreeNode* root ){
        if( root == NULL){
            return NULL ;
        }
        TreeNode* node = new TreeNode( root->val ) ;
        node->left = give( root->left ) ;
        node->right = give( root->right ) ;
        return node ;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if( root == NULL ){
            return NULL ;
        }
        while( root!= NULL ){
            if( root->val == val ){
                return give(root) ;
            }
            else if( root->val < val ){
                root = root->right ;
            }
            else{
                root = root->left ;
            }
        }
        return NULL ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna