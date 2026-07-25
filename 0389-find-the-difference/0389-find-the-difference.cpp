class Solution {
public:
    char findTheDifference(string s, string t) {
       int n = t.size() ;
       unordered_map<char,int> mp ;
       for( int i=0 ; i<n ; i++ ){
        mp[t[i]]++ ;
       }
       for( int i=0 ; i<n-1 ; i++ ){
        mp[s[i]]-- ;
        if( mp[s[i]] == 0 ){
           mp.erase(s[i]) ; 
        }
       }
       auto it = mp.begin() ;
       return it->first ;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna