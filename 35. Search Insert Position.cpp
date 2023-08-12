class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return pos(nums, 0, nums.size() - 1, target);
    }
    
    int pos(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return end + 1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] < target) {
            return pos(nums, mid + 1, end, target);
        }
        if (nums[mid] > target) {
            return pos(nums, start, mid - 1, target);
        }
        return mid;
    }
};
