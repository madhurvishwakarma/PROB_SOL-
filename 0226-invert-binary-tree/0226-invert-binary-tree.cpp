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
// class Solution {
// public:
//     void copy( TreeNode* root , TreeNode* node ){
//         if( root == NULL ){
//             node = NULL ;
//             return ;
//         }
//         node = new TreeNode(root->val);
//         copy( root->right , node->left ) ;
//         copy( root->left , node->right ) ;
//     }
//     TreeNode* invertTree(TreeNode* root) {
//         TreeNode* node = NULL ;
//         copy( root , node ) ;
//         return node ;
//     }
// };
class Solution {
public:
    void copy(TreeNode* root, TreeNode*& node) {    // very important that we have to pass by refrence and not by value 
        if (root == NULL) {
            node = NULL;
            return;
        }

        node = new TreeNode(root->val);

        // Invert while copying
        copy(root->right, node->left);
        copy(root->left, node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode* node = NULL;
        copy(root, node);
        return node;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna