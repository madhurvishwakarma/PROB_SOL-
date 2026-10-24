class Solution {
public:
    int date( string s ){
        int month = stoi( s.substr(0,2) ) ;                 // "MM"
        int day   = stoi( s.substr(3,2) ) ;                 // "DD"
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31} ; // non-leap year
        int total = day ;
        for( int i=0 ; i<month-1 ; i++ ){                   
            total += days[i] ;
        }
        return total ;                                      // day number in the year
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max( date(arriveAlice) , date(arriveBob) ) ;  // later arrival
        int end   = min( date(leaveAlice) , date(leaveBob) ) ;    // earlier departure
        return max( 0 , end - start + 1 ) ;                       // +1 because both days count
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna