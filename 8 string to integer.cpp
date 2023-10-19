class Solution {
public:
    int myAtoi(string s) {
       int result = 0;
        int sign = 1;
        int i = 0;
        
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        
        // Check for optional sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        
        // Convert digits to integer
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;

    }
};
