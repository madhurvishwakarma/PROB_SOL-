class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size() ;
        vector<int> v(26,0) ;
        for( auto x : s ) v[x - 'a']++ ; 
        string half = "" ;
        char mid = 0 ;
        for( int i=0 ; i<26 ; i++ ){
            half += string( v[i]/2 , 'a'+i ) ;
            if( v[i]%2 == 1 ) mid = 'a' + i ;
        }
        string rev = half ;
        reverse(rev.begin() , rev.end()) ;
        string result = half ;
        if( n%2 == 1 ) result += mid ;
        result += rev ;
        return result ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna