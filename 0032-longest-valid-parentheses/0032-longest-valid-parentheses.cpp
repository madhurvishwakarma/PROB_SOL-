class Solution {
public:
    int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);              // sentinel: base for length calculation
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();                          // try to match top
            if (st.empty()) st.push(i);        // nothing to match -> new base
            else maxLen = max(maxLen, i - st.top());
        }
    }
    return maxLen;
}
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna