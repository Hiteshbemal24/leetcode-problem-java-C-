class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
       sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                int start = i + 1, end = nums.size() - 1;
                while (start < end) {
                    int sum = nums[i] + nums[start] + nums[end];
                    if (sum == 0){
                        res.push_back({nums[i], nums[start], nums[end]});
                       
                        int startVal = nums[start];
                        int endVal = nums[end];
                        while (start < end && startVal == nums[start]) {
                            start ++;
                        }
                        while (end > start && endVal == nums[end]) {
                            end --;
                        }
                    }
                    else if (sum < 0) {
                        start ++;
                    }
                    else {
                        end --;
                    }
                }
            }
        }
        return res;  
    }
};
