class Solution {
public:
    int lengthOfLastWord(string s) {
        int count  = 0 ;
        int go = s.size()-1 ;
        while( s[go] == ' '){
            go-- ;
        }
        for( int i = go ; i >= 0 ; i-- ){
            if( s[i] == ' ' && count != 0 ){
                return count ;
            }
            count++ ;
        }
        return count  ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna