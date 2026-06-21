class Solution {
public:
    int maxDistance(string moves) {
        // pair<int, int > v(0,0) ;
        // int sum = 0 ;
        // for( int i = 0 ; i < moves.size() - 1 ; i++ ){
        //     if( moves[i] == 'U'){
        //         v.second +=  -1 ;
        //     }
        //     else if( moves[i] == 'D' ){
        //         v.second += 1 ;
        //     }
        //     else if( moves[i] == 'L' ){
        //         v.first += -1 ;
        //     }
        //     else if( moves[i] == 'R' ){
        //         v.first += 1 ;
        //     }
        //     else if( moves[i] == '_'){
        //        sum++ ;
        //     }
        // }
        // return abs(v.first) + abs( v.second) + sum ;
        int x = 0, y = 0;
        int wildcards = 0;
        
        for (char move : moves) {
            if (move == 'U') y += 1;
            else if (move == 'D') y -= 1;
            else if (move == 'L') x -= 1;
            else if (move == 'R') x += 1;
            else if (move == '_') wildcards += 1;
        }
        return abs(x) + abs(y) + wildcards;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna