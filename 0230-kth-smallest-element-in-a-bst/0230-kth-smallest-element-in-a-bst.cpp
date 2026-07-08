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
    int kthSmallest(TreeNode* root, int k) {
        if( root == NULL ){
            return 0 ;
        }
        stack<TreeNode*> st ;
        st.push(root) ;
        int count = 1 , ans = 0 ;
        TreeNode* node = root ;
        while( 1 ){
            if( node != NULL ){
                st.push(node) ;
                node = node->left ;
            }
            else{
                if( st.empty()){
                    break ; 
                }
                node = st.top() ;
                st.pop() ;
                ans = node->val ;
                node = node->right ;
                if( count == k ){
                    break ;
                }
                count++ ;
            }
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna