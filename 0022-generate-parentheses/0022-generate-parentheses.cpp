class Solution {
public:
    bool isValid( string& s ){
        int count = 0 ;
        for( auto x : s ){
            if( x == '(') count++ ;
            else count-- ;
            if( count < 0 ) return false ;
        }
        return count == 0 ;
    }
    vector<string> result ;
    void solve( string& s , int n ){
        if( s.size() == 2*n ){
            if( isValid(s) == true ) result.push_back(s) ;
            return ;
        }
        s.push_back('(') ;
        solve( s , n ) ;
        s.pop_back() ;
        s.push_back(')') ;
        solve( s , n ) ;
        s.pop_back() ;
    }
    vector<string> generateParenthesis(int n) {
        string s = "" ;
        solve( s , n ) ;
        return result ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna