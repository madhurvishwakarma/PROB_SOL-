class DisJoint {
    public:
    vector<int> size , parent ;
    DisJoint( int n ){
        size.resize(n , 1 ); 
        parent.resize( n) ;
        for( int i=0 ; i<n ;i++ ){
            parent[i] = i ;
        }
    }
    int findPar( int node ){
        if( node == parent[node]) return node ;
        return parent[node] = findPar( parent[node]) ;
    }
    void UBS( int u , int v ){
        int U = findPar( u) ;
        int V = findPar( v ) ;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=0,m=0 ;
        for( auto x : stones ){
            n = max( n , x[0]) ;
            m = max( m , x[1]) ;
        }
        DisJoint ds( n + m + 2 ) ; // very imp that we have added 2 to create extra room for the nodes !!!!!
        unordered_map<int,int> mp ;
        for( auto x : stones ){
            int r = x[0] ;
            int c = x[1]+n+1 ; // very imp that we are moving col after row means if row = 0->n then col = n+1+column number !!!
            ds.UBS(r,c) ;
            mp[r] = 1 ;
            mp[c] = 1 ;
        }
        int count = 0 ;
        for(auto x : mp ){
            if( ds.findPar(x.first) == x.first ){
                count++ ;
            }
        }
        return stones.size()-count ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna