class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        if( grid[0][0] != 0 || grid[n-1][n-1] != 0 ) return -1 ;
        if( n == 1 && grid[0][0] == 0 ) return n ;
        vector<vector<int>> dist( n , vector<int>( n ,INT_MAX)) ;
        dist[0][0] = 1 ;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int,pair<int,int>>>> q ;
        q.push({1 ,{ 0,0}}) ;
        int dr[] = { -1,1,0,0} ;
        int dc[] = { 0,0,-1,1} ;
        while( !q.empty()){
            auto it = q.top() ;
            int d = it.first;
            int row = it.second.first ;
            int col = it.second.second ;
            q.pop() ;
            for( int i=-1 ; i<=1 ;i++ ){
                for( int j =-1 ; j<=1 ; j++ ){
                    int r = row+i ;
                    int c = col+j ;
                    if( r>=0 && r<n && c>=0 && c<n && grid[r][c]==0 && d+1 < dist[r][c]){
                        if( r == n-1 && c == n-1 ) return d+1 ;
                        q.push({d+1,{r,c}}) ;
                        dist[r][c] = d + 1 ;
                    }
                }
            }
            }
        return -1 ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna