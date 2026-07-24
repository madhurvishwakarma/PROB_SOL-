class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size() ;
        vector<vector<int>> adj(n) ;
        for( int i=0 ; i<n ; i++ ){
            if( edges[i] != -1 ){
                adj[i].push_back(edges[i]) ;
            }
        }
        vector<int> vis( n , 0 ) ;
        vector<int> path( n , 0 ) ;
        vector<int> dist( n , 0 ) ;
        int ans = -1 ;
        for( int i =0 ; i< n ; i++ ){
            if( !vis[i]){
                dfs( i , adj , vis , path , dist, ans , 0) ;
            }
        }
        return ans ;
    }
    void dfs( int node , vector<vector<int>>& adj , vector<int>& vis , vector<int>& path , vector<int>& dist, int& ans , int d ){
        vis[node] = 1 ;
        path[node] = 1 ;
        dist[node] = d ;

        for( auto x : adj[node]){
            if( !vis[x]){
                dfs(x,adj,vis,path,dist,ans,d+1 ) ;
            }
            else if( path[x] == 1 ){
                int count = dist[node] - dist[x] + 1 ;
                ans = max( ans , count ) ;
            }
        }
        path[node] = 0 ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna