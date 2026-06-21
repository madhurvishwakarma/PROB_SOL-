class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size() ;
        int l = 0 ;
        int r = k-1 ;
        int count = 0 ;
        while( count*k <= n-1 ){
         l = count*k ;
         r = min(count*k + k-1 , n-1) ;
        while( l <= r ){
            char temp = s[r] ;
            s[r] = s[l] ;
            s[l] = temp ;
            l++ ;
            r-- ;
         }
         count += 2 ;
        }
        return s ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna