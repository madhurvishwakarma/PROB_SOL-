class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n = s1.size();
        int i = 0;
        while (i < n) {
            while (i < n && s1[i] == s2[i]) i++;    
            if (i == n) break;
            string a, b;
            while (i < n && s1[i] != s2[i]) {        
                a += s1[i];
                b += s2[i];
                i++;
            }
            ans.push_back({a, b});
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna