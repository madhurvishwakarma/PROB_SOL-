class DisJoint {
    public: 
    vector<int> size , parent ;
    DisJoint( int n ){
        size.resize( n , 1) ;
        parent.resize( n) ;
        for( int i=0 ;i<n ; i++ ){
            parent[i] = i ;
        }
    }
    int findPar( int node ){
        if( node == parent[node]) return node ;
        return parent[node] = findPar(parent[node]) ;
    }
    void UBS( int u , int v ){
        int U = findPar(u) ;
        int V = findPar(v) ;
        if( U == V ) return ;
        if(size[U] > size[V]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJoint ds(n) ;
        int xtra = 0 ;
        for( auto x : connections){
            int u = x[0] ;
            int v = x[1] ;
            if( ds.findPar(u) == ds.findPar(v)) xtra++ ;
            else ds.UBS(u,v) ;
        }
        int count = 0 ;
        for( int i=0 ; i<n ; i++ ){
            if( ds.parent[i] == i ) count++ ;
        }
        if( xtra >= count - 1 ) return count - 1 ;
        return -1 ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna