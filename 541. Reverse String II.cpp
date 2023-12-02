class Solution {
public:
    string reverseStr(string s, int k) {
        string ans = "";
        int n = s.size() - 1; 
        int i = 0; 
        for (;;) {
            int j = min(n, i + k - 1);
            for (j; j >= i; --j) ans += s[j];
            for (int l = i + k; l < i + 2 * k; ++l) {
                if (l > n) return ans; 
                ans += s[l];
            }
            i += 2 * k; 
        }
        return "cum";  
    }
};
