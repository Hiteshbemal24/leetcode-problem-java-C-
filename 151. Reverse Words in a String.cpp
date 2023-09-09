class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        int size = s.size();
        int i = size-1; int j = size-1;
        while (i >= 0){
            if (s[i] == ' ') {
                while (s[i] == ' '){
                    i--;
                    if (i<0) return ans;
                }
                if (ans != "") ans += ' ';
                j = i;
            }
            if (s[i] != ' ') {
                while(s[i] != ' '){
                    i--;
                    if (i<0) break; 
                }
                ans += s.substr(i+1,j-i);
                j = i;
            }
        }
        return ans;
    }
};
