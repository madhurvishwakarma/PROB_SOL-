class Solution {
public:
    // turn every ")" or "))" into a single ')' token; count lone ')' fixes
    string MakeValid(string s, int &ans) {
        int n = s.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                res.push_back('(');
            } else {
                if (i + 1 < n && s[i+1] == ')') i++;  // full "))"
                else ans++;                            // lone ')': add one ')'
                res.push_back(')');                    // one token = one "))"
            }
        }
        return res;
    }

    int minInsertions(string s) {
        int ans = 0;
        string s1 = MakeValid(s, ans);
        int count = 0;
        for (char x : s1) {
            if (x == '(') count++;
            else if (count > 0) count--;
            else ans++;                // no '(' to match: add one '('
        }
        return ans + count * 2;        // each leftover '(' needs "))"
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna