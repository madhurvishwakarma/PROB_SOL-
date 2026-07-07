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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v ;
        if( root == NULL ){
            return v ;
        }
        queue<TreeNode*> q ;
        q.push( root ) ;
        while( !q.empty() ){
            vector<int> lvl ;
            int size = q.size() ;
            for( int i= 0; i< size ;i++ ){
                TreeNode* node = q.front() ;
                q.pop() ;
                if( node->left) q.push(node->left) ;
                if( node->right) q.push( node->right) ;
                lvl.push_back(node->val) ;
            }
            v.push_back(lvl) ;
        }
        reverse(v.begin() , v.end()) ;
        return v ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna