class DisJoint{
    public :
    vector<int> size , parent ;
    DisJoint(int n ){
        size.resize(n , 1) ;
        parent.resize( n) ;
        for( int i=0 ; i<n ;i++ ){
            parent[i] = i ;
        }
    }
    int findPar( int node ){
        if( node == parent[node]){
            return node ;
        }
        return parent[node] = findPar(parent[node]) ;
    }
    void UBS( int u , int v ){
        int U = findPar(u) ;
        int V = findPar(v) ;
        if( U == V ) return ;
        if( size[U] > size[V]){
            parent[V] = U ;
            size[U] += size[V] ;
        }
        else{
            parent[U] = V ;
            size[V] += size[U] ;
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        DisJoint ds(n*n) ; 
        unordered_set<int> st ;
        for( int i=0 ; i<n ; i++ ){
            for( int j=0 ; j<n ; j++ ){
                if( grid[i][j] == 0 ) continue ;
                int dr[] = { -1,1,0,0 } ;
                int dc[] = { 0,0,-1,1} ;
                for( int k=0 ; k<4 ;k++ ){
                    int nr = i + dr[k] ;
                    int nc = j + dc[k] ;
                    if( nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 ){
                        int node = ds.findPar(i*n + j ) ;
                        int adjN = ds.findPar( nr*n + nc) ;
                        ds.UBS(node,adjN) ;
                    }
                }
            }
        }
        int area = 0 ;
for( int i=0 ; i<n ; i++ ){
    for( int j=0 ; j<n ; j++ ){
        if( grid[i][j] == 1 ) continue ;
        int dr[] = { -1,1,0,0 } ;
        int dc[] = { 0,0,-1,1} ;
        unordered_set<int> st ;
        for( int k=0 ; k<4 ;k++ ){
            int nr = i + dr[k] ;
            int nc = j + dc[k] ;
            if( nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 ){
                int node = ds.findPar(nr*n + nc ) ;
                st.insert(node) ;
            }
        }
        int count = 1 ;
        for(auto x : st){
            count += ds.size[x] ;
        }
        area = max( area , count ) ;
    }          
}             

for( int i=0 ; i<n*n ; i++ ){
    area = max( area , ds.size[ds.findPar(i)]) ;
}
return area ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna