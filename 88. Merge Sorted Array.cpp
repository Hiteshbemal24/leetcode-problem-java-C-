class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       m--;
        n--;
        for (int i = m + n + 1; i >= 0; i--) {
            int a = m >= 0 ? nums1[m] : INT_MIN;
            int b = n >= 0 ? nums2[n] : INT_MIN;
            if (a > b) {
                nums1[i] = a;
                m--;
            } else {
                nums1[i] = b;
                n--;
            }
        }
    }
};
