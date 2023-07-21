class Solution {
public:
    string intToRoman(int num) {
        int base[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::string chars[] = {"M","CM","D","CD","C","XC","L","XL","X","IX", "V", "IV", "I"};
        std::string res = "";
        for (int i = 0; i < sizeof(base)/sizeof(base[0]); i ++) {
            if (num / base[i] > 0) {
                for (int j = 0; j < num/base[i]; j ++) {
                    res = res + chars[i];
                }
                num = num - (num / base[i]) * base[i];
            }
        }
        return res;
    }
};
