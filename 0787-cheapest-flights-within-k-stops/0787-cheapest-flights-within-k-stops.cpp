class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n) ;
        for( auto it : flights){
            adj[it[0]].push_back({it[1],it[2]}) ;
        }
        vector<int> dist(n,INT_MAX) ;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,src}}) ;
        while(!q.empty()){
            int stop = q.front().first ;
            int d = q.front().second.first ;
            int node = q.front().second.second ;
            q.pop();
            for( auto x : adj[node]){
                int edgeN = x.first ;
                int edgeW = x.second ;
                if( d+edgeW < dist[edgeN] && stop <= k ){
                    dist[edgeN] = d+ edgeW ;
                    q.push({ stop+1 ,{d+ edgeW , edgeN}}) ;
                }
            }
        }
        if( dist[dst] == INT_MAX) return -1 ;
        return dist[dst];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna