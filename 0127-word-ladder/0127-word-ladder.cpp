class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st( wordList.begin() , wordList.end()) ;
        queue<pair<string,int>> q ;
        q.push({beginWord , 1}) ;
        st.erase(beginWord) ;
        while( !q.empty()){
            string node = q.front().first ; 
            int count = q.front().second ;
            q.pop() ;
            for( int i =0 ; i< node.size() ; i++ ){
                char org = node[i] ;
                for( char ch = 'a' ; ch <= 'z' ;ch++ ){
                    node[i] = ch ;
                    if( st.find(node) != st.end()){
                        q.push({ node , count+1 }) ;
                        st.erase(node) ;
                    }
                }
                node[i] = org ;
            }
            if( node == endWord ) return count ;
        }
        return 0 ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna