// class Solution {
// public:
//     string evaluate(string s, vector<vector<string>>& knowledge) {
//         unordered_map<string, string> mp;
//         for (auto& k : knowledge) mp[k[0]] = k[1];   // key -> value

//         string res;
//         int n = s.size();
//         for (int i = 0; i < n; i++) {
//             if (s[i] == '(') {
//                 int j = i + 1;
//                 while (s[j] != ')') j++;             // find closing bracket
//                 string key = s.substr(i + 1, j - i - 1);
//                 res += mp.count(key) ? mp[key] : "?";
//                 i = j;                                // skip past ')'
//             } else {
//                 res += s[i];
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int m = s.size();
        unordered_map<string, string> mp;
        for (auto x : knowledge) mp[x[0]] = x[1];

        string ans = "";
        string temp = "";
        bool flag = false;
        for (int j = 0; j < m; j++) {
            if (s[j] == '(') { flag = true; continue; }
            if (s[j] == ')') {
                flag = false;
                ans += mp.count(temp) ? mp[temp] : "?";
                temp = "";
                continue;
            }
            if (flag) temp.push_back(s[j]);
            else ans.push_back(s[j]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna