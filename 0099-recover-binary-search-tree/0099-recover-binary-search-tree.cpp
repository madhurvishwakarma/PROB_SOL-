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
private: 
    TreeNode* first ;
    TreeNode* last ;
    TreeNode* mid ;
    TreeNode* prev ;
    void inorder( TreeNode* root ){
        if( root == NULL ){
            return ;
        }
        inorder(root->left) ;
        if( prev != NULL && root->val < prev->val ){
            if( first == NULL ){
                first = prev ;
                mid = root ;
            }
            else{
                last = root ;
            }
        }
        prev = root ;
        inorder( root->right) ;
    }
public:
    void recoverTree(TreeNode* root) {
        first = last = mid = NULL ;
        prev = new TreeNode(INT_MIN) ;
        inorder(root) ;
        if( first && last ) swap( first->val ,last->val ) ;
        else if( first && mid ) swap( first->val , mid->val) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna