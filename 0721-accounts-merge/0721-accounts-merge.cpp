class DisJoint{
    public :
    vector<int> size , parent ;
    DisJoint(int n ){
        size.resize(n , 1) ;
        parent.resize( n) ;
        for( int i=0 ; i<n ;i++ ){
            parent[i] = i ;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size() ;
        DisJoint ds(n) ;
        unordered_map<string , int> mp ;
        for( int i=0 ; i<n ; i++ ){
            for( int j=1 ; j<accounts[i].size() ; j++ ){
                if( mp.find( accounts[i][j]) == mp.end()) mp[accounts[i][j]] = i ;
                else{
                    ds.UBS( i , mp[accounts[i][j]]) ;
                }
            }
        }
        vector<vector<string>> merge(n) ;
        for( auto x : mp ){
            string node = x.first ;
            int val = ds.findPar(x.second); 
            merge[val].push_back(node) ;
        }
        vector<vector<string>> ans ;
        for( int i=0 ; i<n ; i++ ){
            if( merge[i].size() == 0) continue ;
            sort( merge[i].begin() , merge[i].end()) ;
            vector<string> temp ;
            temp.push_back(accounts[i][0]) ;
            for( auto x : merge[i]){
                temp.push_back(x) ;
            }
            ans.push_back(temp) ;
        }
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna