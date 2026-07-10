class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size() ;
        vector<int> vis(n , 0) ;
        vis[0] = 1 ;
        queue<int> q ;
        q.push(0) ;
        vector<int> v ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            v.push_back(node) ;
            for( auto i : adj[node]){
                if(!vis[i]){vis[i] = 1 ;
                q.push(i) ;}
            }
        }
        return v ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna