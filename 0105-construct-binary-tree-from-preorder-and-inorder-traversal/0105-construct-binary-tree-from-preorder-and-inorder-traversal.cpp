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
    TreeNode* build( vector<int>& inorder , int instart , int inend , vector<int>& preorder , int prestart , int preend , map<int , int>& inmap ){
        if( instart > inend || prestart > preend ){
            return NULL ;
        }
        TreeNode* node = new TreeNode(preorder[prestart]) ;
        int inRoot = inmap[node->val] ;
        int numleft = inRoot - instart ;
        node->left = build( inorder , instart , inRoot-1 , preorder , prestart + 1 , prestart + numleft , inmap ); 
        node->right = build( inorder , inRoot+1 , inend , preorder , prestart+numleft+1 , preend ,inmap ) ;
        return node ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int , int> mp ;
        for( int i = 0 ; i<inorder.size() ; i++ ){
            mp[inorder[i]] = i ;
        }
        return build( inorder , 0 , inorder.size()-1 , preorder , 0 , preorder.size()-1 , mp ) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna