class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> mp1 , mp2 ;
        int n = t.size() ;
        for( int i=0 ; i<n ; i++ ){
            mp1[t[i]] = i ;
            mp2[s[i]] = i ;
        } 
        int sum = 0 ; 
        for( auto x : s ){
            sum += abs( mp1[x] - mp2[x]) ;
        }
        return sum ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna