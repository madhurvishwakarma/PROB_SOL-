#include <string>
#include <algorithm>

class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        std::string ans = "";
        int min_len = 1e9;
        int ones = 0;
        int l = 0;
        
        for (int r = 0; r < s.length(); r++) {
            if (s[r] == '1') {
                ones++;
            }
            
            while (ones == k) {
                int curr_len = r - l + 1;
                std::string curr_str = s.substr(l, curr_len);
                
                if (curr_len < min_len) {
                    min_len = curr_len;
                    ans = curr_str;
                } else if (curr_len == min_len) {
                    if (curr_str < ans) {
                        ans = curr_str;
                    }
                }
                
                if (s[l] == '1') {
                    ones--;
                }
                l++;
            }
        }
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna