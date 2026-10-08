class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) ans += c;   // skip the outermost '('
                depth++;
            } else {
                depth--;
                if (depth > 0) ans += c;   // skip the outermost ')'
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna