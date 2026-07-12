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
    TreeNode* BST( vector<int>& arr , int start , int end ){
        if( arr.size() == 0 ){
            return NULL ;
        }
        if( start > end ){
            return NULL ;
        }
        int mid = start + (end-start)/2 ;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = BST( arr , start , mid-1 ) ;
        node->right = BST( arr , mid+1 , end ) ;
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST( nums , 0 , nums.size()-1 ) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna