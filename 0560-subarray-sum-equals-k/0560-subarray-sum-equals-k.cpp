class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if( nums.size() == 0 ){
            return 0 ;
        }
        int count = 0 ;
        int sum = 0 ;
        unordered_map<int, int > mp ;
        mp[0] = 1 ; // very important 
        for( int i = 0 ; i< nums.size() ; i++ ){
            sum += nums[i] ;
            if( mp.count(sum-k) ){
                count += mp[sum-k] ;
            }
                mp[sum]++ ;
        }
        return count ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna