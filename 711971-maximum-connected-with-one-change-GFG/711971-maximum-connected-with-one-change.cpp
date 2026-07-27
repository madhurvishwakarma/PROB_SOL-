class DisJoint {
    public : 
    vector<int> parent , size ;
    DisJoint( int n ){
        parent.resize(n) ;
        size.resize(n,1) ;
        for( int i=0 ;i<n ; i++ ){
            parent[i] = i ;
        }
    }
    int findPar(int node ){
        if( parent[node] == node ) return node ;
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
    int maxConnection(vector<vector<int>>& grid) {
        // code here
      int n = grid.size() ;
      int m = grid[0].size() ;
      DisJoint ds( n*m ) ;
      for( int i=0 ; i<n ; i++ ){
          for( int j=0 ; j<m ;j++ ){
              if( grid[i][j] == 0 ) continue ;
              int dr[] = { -1 ,1 , 0, 0 } ;
              int dc[] = { 0,0,-1,1 };
              for( int k=0 ; k<4 ; k++ ){
                  int nr = i+dr[k] ;
                  int nc = j+dc[k] ;
                  if( nr >= 0 && nc>= 0 && nr< n && nc <m && grid[nr][nc] == 1 ){
                      int node = ds.findPar(i*n + j) ;
                      int adjN = ds.findPar(nr*n+ nc) ;
                      ds.UBS(node,adjN) ;
                  }
              }
          }
      }
      int ans = 0 ; 
      for( int i=0 ; i<n ; i++ ){
          for( int j=0 ; j<m ;j++ ){
              if( grid[i][j] == 1 ) continue ;
              unordered_set<int> st ;
              int dr[] = { -1 ,1 , 0, 0 } ;
              int dc[] = { 0,0,-1,1 };
              for( int k=0 ; k<4 ; k++ ){
                  int nr = i+dr[k] ;
                  int nc = j+dc[k] ;
                  if( nr >= 0 && nc>= 0 && nr< n && nc <m && grid[nr][nc] == 1 ){
                      int adjN = ds.findPar(nr*n+ nc) ;
                      st.insert(adjN) ;
                  }
              }
              int count = 1 ;
              for(auto x : st){
                  count += ds.size[ds.findPar(x)] ;
              }
              ans = max( count , ans ) ;
          }
      }
      for( int i=0 ;i<n*m ; i++ ){
          ans = max( ans, ds.size[ds.findPar(i)]) ;
      }
      return ans ;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna