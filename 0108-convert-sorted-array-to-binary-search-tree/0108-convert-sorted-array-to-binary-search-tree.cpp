/** * Definition for a binary tree node.
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
    TreeNode* BST( vector<int>& nums , int start , int end ){
        // Added check for start > end to prevent invalid index access
        if( start > end ){
            return NULL ;
        }
        if( nums.size() == 0 ){
            return NULL ;
        }
        int mid = start + (end-start)/2 ;
        TreeNode* node = new TreeNode(nums[mid]) ;
        node->left = BST( nums , start , mid-1 ) ; // Fixed: mid-1 for left subtree
        node->right = BST( nums , mid+1 , end ) ;
        return node ;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0 ;
        int end = nums.size()-1 ;
        return BST( nums , start , end ) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna