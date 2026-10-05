// class Solution {
// public:
//     bool isValid( string& s ){
//         int count = 0 ;
//         for( auto x : s ){
//             if( x == '(' ) count++ ;
//             else count-- ;
//             if( count < 0 ) return false ;
//         }
//         if( count == 0 ) return true ;
//         return false ;
//     }
//     int scoreOfParentheses(string s) {
          
//     }
// };
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);   // score accumulated at current depth
        for (char c : s) {
            if (c == '(') {
                st.push(0);                 // new nesting level starts at 0
            } else {
                int v = st.top(); st.pop();
                int score = (v == 0) ? 1 : 2 * v;   // "()" = 1, "(A)" = 2*A
                st.top() += score;          // add to the enclosing level
            }
        }
        return st.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna