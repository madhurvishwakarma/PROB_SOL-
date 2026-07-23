class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n) ;
        for( auto x : roads){
            adj[x[0]].push_back({x[1] ,x[2]}) ;
            adj[x[1]].push_back({x[0] ,x[2]}) ;
        }
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> q ;
        q.push({0LL , 0}) ;
        vector<long long> dist(n , LLONG_MAX) ;
        vector<int> ways(n, 0) ;
        dist[0] = 0 ;
        ways[0] = 1 ;
        int mod = 1000000007 ;
        while(!q.empty()){
            int node = q.top().second ;
            long long d = q.top().first ;
            q.pop() ;
            for( auto x : adj[node]){
                int edgeN = x.first ;
                long long edgeW = x.second ;
                if( d+edgeW < dist[edgeN]){
                    dist[edgeN] = d+edgeW ;
                    ways[edgeN] = ways[node]%mod ;
                    q.push({d+edgeW , edgeN}) ;
                }
                else if(d+edgeW == dist[edgeN]){
                    ways[edgeN] = (ways[edgeN] + ways[node])%mod ;
                }
            }
        }
        return ways[n-1] ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna