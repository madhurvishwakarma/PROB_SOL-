class Solution {
public:
    string s;
    int pos = 0;

    set<string> parseExpr() {
        set<string> result = parseTerm();
        while (pos < s.size() && s[pos] == ',') {
            pos++;                              // skip ','
            set<string> term = parseTerm();
            result.insert(term.begin(), term.end());
        }
        return result;
    }

    set<string> parseTerm() {
        set<string> result = {""};              // identity for concatenation
        while (pos < s.size() && s[pos] != ',' && s[pos] != '}') {
            set<string> factor = parseFactor();
            set<string> combined;
            for (auto& a : result)
                for (auto& b : factor)
                    combined.insert(a + b);
            result = combined;
        }
        return result;
    }

    set<string> parseFactor() {
        if (s[pos] == '{') {
            pos++;                              // skip '{'
            set<string> result = parseExpr();
            pos++;                              // skip '}'
            return result;
        }
        int start = pos;
        while (pos < s.size() && isalpha(s[pos])) pos++;
        return { s.substr(start, pos - start) };
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;
        set<string> result = parseExpr();
        return vector<string>(result.begin(), result.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna