class Solution {
public:
    string reverseWords(string s) {
        vector<string> v ;
        string temp ;
        for( auto x : s ){
             if( x == ' ' ){                    
                if( !temp.empty() ){         
                    v.push_back(temp) ;
                    temp = "" ;
                }
            }
            else temp.push_back(x) ;
        }
        if( !temp.empty() ) v.push_back(temp) ;
        int n = v.size() ;
        string ans = "" ;
        for( int i=0 ;i<n ; i++ ){
            ans += v[n-1-i] ;
            if( i != n-1 ) ans += " " ;
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna