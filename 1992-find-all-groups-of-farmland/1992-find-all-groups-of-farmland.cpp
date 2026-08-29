class Solution {
public:
    vector<int> bfs( int r , int c , vector<vector<int>>& land , vector<vector<int>>& vis ){
        int n = land.size() ;
        int m = land[0].size() ;
        vis[r][c] = 1 ;
        queue<pair<int,int>> q ;
        q.push({r,c}) ;
        int mini = r * m + c;   // seed the trackers with the starting cell
        int maxi = r * m + c;
        int rm = r, cm = c;
        int rM = r, cM = c;
        int dr[] = {-1,1,0,0} ;
        int dc[] = {0,0,-1,1} ;
        while( !q.empty() ){
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop();
            for( int i=0 ;i<4 ;i++ ){
                int nr = row + dr[i] ;
                int nc = col + dc[i] ;
                if( nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] == 0 && land[nr][nc] == 1){
                    vis[nr][nc] = 1 ;
                    q.push({ nr , nc }) ;
                    if( mini >= nr*m + nc ){
                        mini = nr*m + nc ; 
                        rm = nr ; 
                        cm = nc ;
                    }
                    if( maxi <= nr*m + nc ){
                        maxi = nr*m + nc ;
                        rM = nr ; 
                        cM = nc ;
                    }
                }
            }
        }
        return {rm,cm,rM,cM} ;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size() ;
        int m = land[0].size() ;
        vector<vector<int>> vis( n , vector<int> ( m,0)) ;
        vector<vector<int>> ans ;
        for( int i=0 ;i<n ; i++ ){
            for( int j=0 ;j<m ;j++ ){
                if( vis[i][j] == 0 && land[i][j] == 1 ){
                    ans.push_back(bfs(i,j,land,vis)) ;
                }
            }
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna