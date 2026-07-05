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
    int findLeft( TreeNode* root ){
        if( root == NULL ){
            return 0 ;
        }
        int lh = 0 ;
        while( root ){
            lh++ ;
            root = root->left ;
        }
        return lh ;
    }
    int findRight( TreeNode* root ){
        if( root == NULL ){
            return 0 ;
        }
        int rh = 0 ;
        while( root ){
            rh++ ;
            root = root->right ;
        }
        return rh ;
    } 
    int countNodes(TreeNode* root) {
        if( root == NULL ){
            return 0 ;
        }
        int lh = findLeft( root ) ;
        int rh = findRight( root ) ;
        if( lh == rh ){
            return (1<<lh) - 1 ;
        }
        return  countNodes(root->left) + countNodes(root->right) +1 ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna