class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);  

        int l = 0, r = v.size() - 1;
        while(l < r) {
            int sum = v[l] + v[r];
            if(sum == k) return true;
            else if(sum < k) l++;  
            else r--;               
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna