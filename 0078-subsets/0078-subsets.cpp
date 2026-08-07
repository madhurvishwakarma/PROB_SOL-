class Solution {
public:
    void f( int index , vector<int>& nums , vector<int>& curr , vector<vector<int>>& ans ){
        if( index == nums.size() ){
            ans.push_back( curr ) ;
            return ;
        }
        f( index+1 , nums , curr , ans ) ;
        curr.push_back( nums[index]) ;
        f( index+1 , nums , curr , ans ) ;
        curr.pop_back() ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> curr ;
        vector<vector<int>> ans ;
        f( 0, nums , curr , ans ) ;
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna