class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> ravolqedin = nums1; 
        
        sort(nums1.begin(), nums1.end());
        
        int mn = nums1[0];
        int mn_parity = mn % 2;
        
        for(int i = 1; i < nums1.size(); i++){
            int x = nums1[i];

            if(x % 2 == mn_parity) continue;
            
            bool possible = false;
            
            for(int j = 0; j < i; j++){
                if(x - nums1[j] >= 1){
                    if((x - nums1[j]) % 2 == mn_parity){
                        possible = true;
                        break;
                    }
                }
            }
            
            if(!possible) return false;
        }
        
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna