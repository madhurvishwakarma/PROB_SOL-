class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s( nums.begin() , nums.end() ) ;
        int count = 0 ;
        while(1){
            if(s.find(count) == s.end() && count != 0 ) break ;
            count += k ;
        }               
        return count ;                                       
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna