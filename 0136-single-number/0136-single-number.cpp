class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> mp ;
        for( auto x : nums ){
            mp[x]++ ;
        }
        int count = 0 ;
        for( auto x : mp){
            if( x.second == 1){
                count = x.first ;
            }
        }
        return count ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna