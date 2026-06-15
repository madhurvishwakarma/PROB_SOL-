class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map< map<char , int> , vector<string> > mp ;
        int n = strs.size() ;
        for( int i = 0 ; i<n ; i++ ){
            map< char , int > np ;
            for( auto x : strs[i] ){
                np[x]++ ;
            }
            mp[np].push_back(strs[i]) ;
        }
        vector<vector<string>> v;
        for( auto x  : mp ){
            v.push_back( x.second ) ;
        }
        return v ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna