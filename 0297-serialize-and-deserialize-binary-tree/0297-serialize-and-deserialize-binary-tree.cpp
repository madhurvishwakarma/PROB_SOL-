class Codec {
public:
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node == NULL) {
                s += "#,";  // mark null with delimiter
            } else {
                s += to_string(node->val) + ",";  // value + delimiter
                q.push(node->left);   // push left (even if null)
                q.push(node->right);  // push right (even if null)
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream st(data) ;
        string s ;
        getline( st , s , ',') ;
        TreeNode* root = new TreeNode(stoi(s)) ;
        queue<TreeNode*> q ;
        q.push( root ) ;
        while( !q.empty() ){
            TreeNode* node = q.front() ;
            q.pop() ;
            getline( st , s , ',') ;
            if( s == "#" ){
                node->left = NULL ;
            }
            else{
                TreeNode* nodeL = new TreeNode(stoi(s)) ;
                node->left = nodeL ;
                q.push(node->left) ;
            }
            getline(st , s, ',') ;
            if( s == "#"){
                node->right = NULL ;
            }
            else{
                TreeNode* nodeR = new TreeNode(stoi(s)) ;
                node->right = nodeR ;
                q.push(node->right ) ;
            }
        }
        return root ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna