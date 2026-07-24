class Solution {
  public:
      bool isBipartite(int V, vector<vector<int>> &list) {
        vector<vector<int>> edges( V ) ;
        for( int i=0 ; i<list.size() ; i++ ){
            edges[list[i][0]].push_back(list[i][1]) ;
            edges[list[i][1]].push_back(list[i][0]) ;
        }
        vector<int> color( V , -1 ) ;  
        for( int i =0 ; i< V ; i++ ){
            if( color[i] == -1 ){
                if( check( i , edges , color ) == false ){
                    return false ;
                }
            }
        }      
        return true ;
    }   
    bool check( int node , vector<vector<int>>& edges , vector<int>& color ){
        color[node] = 0 ;
        queue<int> q ;
        q.push(node) ;
        while( !q.empty() ){
            int n = q.front() ;
            q.pop() ;
            for( auto x : edges[n]){
                if( color[x] == -1 ){
                    color[x] = !color[n] ;
                    q.push(x) ;
                }
                else if( color[x] == color[n]){
                    return false ;
                }
            }
        }
        return true ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna