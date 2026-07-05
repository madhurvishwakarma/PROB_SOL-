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
    int widthOfBinaryTree(TreeNode* root) {
        if( root == NULL ){
            return 0 ;
        }
        long long ans = INT_MIN ;
        queue<pair<TreeNode* , long long >> q ;
        q.push({ root , 0 }) ;
        while( !q.empty() ){
            int size = q.size() ;
            long long left = 0 , right = 0 ;
            long long mn = q.front().second ;
            for( int i =0 ; i< size ; i++ ){
                long long index = q.front().second-mn ;
                TreeNode* node = q.front().first ;
                q.pop() ;
                if( i == 0 ) left = index ;
                if( i == size-1 ) right = index ;
                if( node->left ) q.push( {node->left , 2*index+1}) ;
                if( node->right ) q.push( {node->right , 2*index+2} ) ;
            }
            ans = max( ans , right-left+1 ) ;
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna