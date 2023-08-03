class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        
        // Generate subsets using backtracking
        generateSubsets(nums, 0, current, result);
        
        return result;
    }
    
private:
    void generateSubsets(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // Add the current subset to the result
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates to avoid duplicate subsets
            }
            
            current.push_back(nums[i]);
            generateSubsets(nums, i + 1, current, result); // Generate subsets recursively
            current.pop_back(); // Backtrack
        }
    }
};