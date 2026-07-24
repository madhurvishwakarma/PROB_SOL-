class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj( V ) ;
        for( int i=0 ; i<edges.size() ; i++ ){
            adj[edges[i][0]].push_back(edges[i][1]) ;
        }
        vector<int> vis( V , 0 ) ;
        vector<int> path( V , 0 ) ;
        for( int i=0 ; i<V ; i++ ){
            if( !vis[i]){
                if( check( i , path , vis , adj ) == true ){
                    return true ;
                }
            }
        }
        return false ;
    }
    bool check( int node , vector<int>& path , vector<int>& vis , vector<vector<int>>& adj ){
        vis[node] = 1 ;
        path[node] = 1 ;
        for( auto x : adj[node]){
            if( !vis[x]){
                if( check( x , path , vis , adj ) == true ){
                    return true ;
                }
            }
            else if( path[x] == 1 ){
                return true ;
            }
        }
        path[node] = 0 ;
        return false ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna