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
    TreeNode* findLastRight( TreeNode* root ){
        if( root->right == NULL ){
            return root ;
        }
        return findLastRight( root->right ) ;
    }
    TreeNode* helper( TreeNode* root ){
        if( root->right == NULL ){
            return root->left ;
        }
        else if( root->left == NULL ){
            return root->right ;
        }
        TreeNode* rightChild = root->right ;
        TreeNode* lastRight = findLastRight(root->left) ;
        lastRight->right = rightChild ;
        return root->left ;
    }
    TreeNode* deleteNode(TreeNode* root , int key) {
        if( root == NULL ){
            return NULL ;
        }
        if( root->val== key ){
            return helper(root) ;
        }
        TreeNode* node = root  ;
        while(root){
            if( root->val > key ){
                if( root->left && root->left->val == key ){
                    root->left = helper( root->left ) ;
                    break ;
                }else{
                    root = root->left ;
                }
            }
            else{
                if( root->right!=NULL && root->right->val == key ){
                    root->right = helper(root->right ) ;
                    break ;
                }else{
                    root = root->right ;
                }
            }
        }
        return node ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna