class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size() ;
        int count = INT_MAX ;
        unordered_map<char , vector<int>> mp ;
        for(int i =0 ;i<n ; i++ ){
            mp[s[i]].push_back(i) ;
        }
        for( auto x : mp ){
            if( x.second.size() == 1 ){
                count = min( count , x.second[0] ) ;
            }
        }
        if( count == INT_MAX ) return -1 ;
        return count ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna