/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark( TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parent , TreeNode* target ){
        queue<TreeNode*> q ;
        q.push(root) ;
        while( !q.empty() ){
            TreeNode* node = q.front() ;
            q.pop() ;
            if( node->left ){ q.push(node->left) ; parent[node->left] = node ;}
            if( node->right ) {q.push(node->right) ;parent[node->right] = node ;}
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent ;
        mark( root , parent , target ) ;
        unordered_map<TreeNode* , bool> visited ;
        queue<TreeNode*> q ;
        q.push(target ) ;
        visited[target] = true ;
        int dist = 0 ;
        while( !q.empty() ){
            int size = q.size() ;
            if( dist == k) break ;
            dist++ ;
            for( int i =0 ; i< size ; i++ ){
                TreeNode* node = q.front() ;
                q.pop() ;
                if( node->left && !visited[node->left]){ q.push(node->left) ; visited[node->left] = true ;}
                if( node->right && !visited[node->right]) {q.push(node->right) ; visited[node->right] = true ;}
                if( parent[node] && !visited[parent[node]]) {q.push( parent[node]) ; visited[parent[node]] = true ;}
            }
        }
        vector<int> v ;
        while( !q.empty() ){
                TreeNode* node = q.front();
                q.pop() ;
                v.push_back(node->val) ;
        }
        return v ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna