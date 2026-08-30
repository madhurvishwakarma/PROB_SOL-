class Solution {
public:
    int FromEnds( int mini , int maxi , vector<int>& nums ){
        int n = nums.size() ;
        int i = 0 ;
        int count = 0 ;
        while( nums[i] != mini ){
            i++ ;
            count++ ;
        }
        int j = n-1 ;
        while( nums[j] != maxi ){
            j-- ;
            count++ ;
        }
        return count+2 ;
    }
    int minimumDeletions(vector<int>& nums) {
    int n = nums.size() ;
    if( n == 1 ) return 1 ;
    int count = 0 ;
    int mini = *min_element( nums.begin() , nums.end() ) ;
    int maxi = *max_element( nums.begin() , nums.end() ) ;

    stack<int> st ;
    st.push(mini) ;
    st.push(maxi) ;
    while(!st.empty()){
        if( nums[count] == mini )st.pop() ;
        else if( nums[count] == maxi ) st.pop() ;
        count++ ;
    }
    int frontOnly = count ;

    // NEW: symmetric scan from the back
    stack<int> st2 ;
    st2.push(mini) ;
    st2.push(maxi) ;
    int backOnly = 0 ;
    int idx = n - 1 ;
    while(!st2.empty()){
        if( nums[idx] == mini ) st2.pop() ;
        else if( nums[idx] == maxi ) st2.pop() ;
        idx-- ;
        backOnly++ ;
    }

    int best = min( frontOnly , backOnly ) ;
    best = min( best , FromEnds( mini , maxi , nums )) ;
    best = min( best , FromEnds( maxi , mini , nums )) ;
    return best ;
}
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna