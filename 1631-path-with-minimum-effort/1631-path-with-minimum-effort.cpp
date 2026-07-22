class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() ;
        int m = heights[0].size() ;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> q ;
        q.push({0 , {0,0}}) ;
        vector<vector<int>> diff( n, vector<int>( m, INT_MAX)) ;
        diff[0][0] = 0 ;
        int dr[] = {-1,1,0,0} ;
        int dc[] = {0,0,-1,1} ;
        while( !q.empty()){
            int dist = q.top().first ;
            int row = q.top().second.first ;
            int col = q.top().second.second ;
            q.pop() ;
            if( row == n-1 && col == m-1 ) return dist ;
            for( int i=0 ; i<4 ;i++ ){
                int r = row + dr[i] ;
                int c = col + dc[i] ;
                if( r>=0 && r<n && c>=0 && c<m){
                    int maxi = max( dist , abs(heights[r][c]-heights[row][col])) ;
                    if( maxi < diff[r][c]){q.push({maxi , {r,c}}) ;
                    diff[r][c] = maxi ;}
                }
            }
        }
        return 0 ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna