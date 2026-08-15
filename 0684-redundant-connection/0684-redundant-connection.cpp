class DSU{
    public :
    vector<int> parent ;
    vector<int> size ;
    DSU( int n ){
        size.resize( n , 1 ) ;
        parent.resize(n) ;
        for( int i=0 ; i<n ; i++ ){
            parent[i] = i ;
        }
    }
    int findPar( int node ){
        if( node == parent[node]) return node ;
        return parent[node] = findPar(parent[node]) ;
    }
    bool DBsize( int u , int v ){
        int U = findPar(u) ;
        int V = findPar(v) ;
        if( U == V ) return false ;
        if( size[U] > size[V] ){
            parent[V] = U ;
            size[U] += size[V] ;
        }
        else{
            parent[U] = V ;
            size[V] += size[U] ;
        }
        return true ;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        DSU ds(n+1) ;
        for( auto x : edges ){
            int node = x[0] ;
            int adjN = x[1] ;
            if( ds.DBsize(adjN , node ) == false ){
                return {node , adjN} ;
            }
        }
        return {} ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna