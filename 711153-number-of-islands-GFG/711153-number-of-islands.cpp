class DJ {
  public:
  vector<int> parent , size ;
  DJ( int n ){
      size.resize( n , 1) ;
      parent.resize(n) ;
      for( int i=0 ; i< n ; i++ ){
          parent[i] =  i ;
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DJ ds(n*m) ;
        int count = 0 ;
        vector<int> ans ;
        vector<vector<int>> vis(n, vector<int> ( m,0)) ;
        for( int i=0 ; i<operators.size() ; i++ ){
            int r = operators[i][0] ;
            int c = operators[i][1] ;
            if( vis[r][c] == 1 ){
                ans.push_back(count) ;
                continue ;
            }
            vis[r][c] = 1 ;
            count++ ;
            int delrow[] = {-1 , 0 , 1 , 0 } ;  
            int delcol[] = { 0 , 1 , 0 , -1 } ;
            for( int j=0 ; j<4 ; j++ ){
                int nrow = r + delrow[j] ;
                int ncol = c + delcol[j] ;
                if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 1 ){
                    if( ds.findPar(r*m + c) != ds.findPar(nrow*m + ncol)){
                        count-- ;
                        ds.UBS(r*m + c , nrow*m + ncol ) ;
                    }
                }
            }
            ans.push_back(count) ;
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna