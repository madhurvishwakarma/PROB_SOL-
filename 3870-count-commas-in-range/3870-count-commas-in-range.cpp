class Solution {
public:
    int countCommas(int n) {
        int count = 0 ;
        if( n >= 1000 ){
            int temp = 1 ;
            if( n <= 100000 ){for( int i=1000 ;i<n ; i++ ) temp++ ;}
            else{
                for( int i=100000 ; i<n ; i++ ) temp++ ;
            }
            count = temp ;
        }
        return count ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna