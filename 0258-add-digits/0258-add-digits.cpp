class Solution {
public:
    int addDigits(int num) {
        int sum = 0 ;
        int temp = num ;
        while( num != 0 ){
            sum+= num%10 ;
            num = num/10 ;
        }
        if( sum  <= 9 ){
            return sum ;
        }
        return addDigits( sum ) ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna