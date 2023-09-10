class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= mergedIntervals.back()[1]) {
                mergedIntervals.back()[1] = max(intervals[i][1], mergedIntervals.back()[1]);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }
        
        return mergedIntervals;
    }
};
