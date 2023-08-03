class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort the intervals based on their start times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> result;
        
        for (const auto& interval : intervals) {
            if (result.empty() || interval[0] > result.back()[1]) {
                // Non-overlapping interval, add to the result
                result.push_back(interval);
            } else {
                // Overlapping interval, merge with last interval in the result
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        
        return result;
    }
};