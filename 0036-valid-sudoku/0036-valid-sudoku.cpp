class Solution {
public:
    bool checkBlock( vector<vector<char>>& board ){
    for( int bi=0 ; bi<9 ; bi+=3 ){
        for( int bj=0 ; bj<9 ; bj+=3 ){
            unordered_map<char,int> mp ;
            for( int i=bi ; i<bi+3 ; i++ ){
                for( int j=bj ; j<bj+3 ; j++ ){
                    if( board[i][j] == '.' ) continue ;
                    if( ++mp[board[i][j]] > 1 ) return false ;
                }
            }
        }
    }
    return true ;
}
    bool checkRow( vector<vector<char>>& board ){
        int n = board.size() ;
        for( int i=0 ; i<n ; i++ ){
            unordered_map<char,int> mp ;
            for( int j=0 ; j<n ; j++ ){
                if( board[i][j] != '.' ){
                    mp[board[i][j]]++ ;
                }
                if( mp[board[i][j]] > 1 ) return false ;
            }
        }
        return true ;
    }
    bool checkCol( vector<vector<char>>& board ){
        int n = board.size() ;
        for( int i=0 ; i<n ; i++ ){
            unordered_map<char,int> mp ;
            for( int j=0 ; j<n ; j++ ){
                if( board[j][i] != '.' ){
                    mp[board[j][i]]++ ;
                }
                if( mp[board[j][i]] > 1 ) return false ;
            }
        }
        return true ;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       if( checkBlock(board) && checkRow(board) && checkCol(board) ) return true ;
       return false ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna