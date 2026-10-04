class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;   // lo = min possible open count, hi = max possible open count
        for (char c : s) {
            if (c == '(') { lo++; hi++; }
            else if (c == ')') { lo--; hi--; }
            else { lo--; hi++; }   // '*' as ')' lowers lo, as '(' raises hi

            if (hi < 0) return false;   // too many ')' even in best case
            if (lo < 0) lo = 0;         // can't go negative -> treat '*' as nothing/'(' here
        }
        return lo == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna