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
        // Edge case: An empty tree is symmetric. Without this check, root->left/right would dereference a null pointer.
        if (root == nullptr) {
            return true;
        }
        return same( root->left , root->right ) ;
    }
    // Time Complexity: O(N), where N is the number of nodes, as each node is visited once.
    // Space Complexity: O(H), where H is the height of the tree due to recursion stack.
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna