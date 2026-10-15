class Solution {
public:

    int sumCounts(vector<int>& nums) {
        int n = nums.size() ;
        int l = 0 , r = 1 ;
        vector<int> ans ;
        while( l < n-1 ){
            unordered_set<int> st ;
            while( r < n-1){
                for( int i=l ; i<=r ; i++ ){
                    st.insert(nums[i]) ;
                }
                ans.push_back(st.size()) ;
                r++ ;
            }
            if( r == n-1 ){
                for( int i=l ; i<=r ; i++ ){
                    st.insert(nums[i]) ;
                }
                ans.push_back(st.size()) ;
                l++ ;
                r = l+1 ;
            }
        }
        long long sum = 0 ;
        for( auto x : ans ){
            sum += x*x ;
        }
        return sum+n ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna