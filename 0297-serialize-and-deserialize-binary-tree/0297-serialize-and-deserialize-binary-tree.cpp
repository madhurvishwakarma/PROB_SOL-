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
        
        // Step 1: split string by ","
        vector<string> vals;
        string curr = "";
        for(char c : data) {
            if(c == ',') {
                vals.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        
        // Step 2: BFS reconstruction
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;  // start from index 1 (skip root)
        
        while(!q.empty() && i < vals.size()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Left child
            if(vals[i] != "#") {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;
            
            // Right child
            if(i < vals.size() && vals[i] != "#") {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna