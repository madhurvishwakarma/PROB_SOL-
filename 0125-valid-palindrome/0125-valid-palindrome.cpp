class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "" ;
        for( auto x : s ){
            x = tolower(x) ;
            if(isalnum(x)){
                ans += x ; 
            }
        }
        int l = 0 ;
        int r = ans.size() - 1 ;
        while( l <= r ){
            if( ans[l] != ans[r] ){
                return false ;
            }
            l++ ;
            r-- ;
        }
        return true ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna