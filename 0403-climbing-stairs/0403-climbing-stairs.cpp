class Solution {
public:
    int climbStairs(int n) {
        if( n <= 1 ){
            return n ;
        }
        int first=1 , second=1 ;
        int curr = 0 ;
        for( int i=2 ; i<=n ; i++ ){
            curr = first + second ;
            first = second ;
            second = curr ;
        }
        return curr ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna