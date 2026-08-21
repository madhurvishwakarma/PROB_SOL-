class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp ;
        for( auto x : s ) mp[x]++ ;
        vector<pair<char,int>> v( mp.begin() , mp.end()) ;
        sort( v.begin() , v.end() , [](pair<char,int>& a , pair<char,int>& b){
            return a.second > b.second ;
        });
        string ans ;
        for( auto x : v ){
            for( int i=0 ;i<x.second ; i++ ){
                ans.push_back(x.first) ;
            }
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna