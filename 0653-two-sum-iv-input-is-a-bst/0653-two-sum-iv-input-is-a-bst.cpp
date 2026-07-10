class BST{
private: 
   stack<TreeNode*> st ;
   bool reverse = false ;
   void pushAll( TreeNode* root ){
    while( root ){
        st.push(root) ;
        if( reverse == false ){
            root = root->left ;
        }
        else{
            root = root->right ;
        }
    }
   }
public: 
   BST(TreeNode* root , bool isreverse){
    reverse = isreverse ;
    pushAll(root) ;
   }
   bool HasNxt(){
    return !st.empty() ;
   }
   int next(){
    TreeNode* node = st.top() ;
    st.pop() ;
    if(reverse == false ){
        pushAll( node->right ) ;
    }
    else{
        pushAll( node->left ) ;
    }
    return node->val ;
   }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if( root == NULL ){
            return false ;
        }
        BST l(root , false) ;
        BST r(root , true ) ;
        int left = l.next() ;
        int right = r.next() ;
        while( left < right ){
            if( left + right == k ) return true ;
            else if( left + right < k ) left = l.next() ;
            else right = r.next() ;
        }
        return false ;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna