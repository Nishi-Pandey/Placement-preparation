class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRecursive(nums, 0, result);
        return result;
    }
    
private:
    void permuteRecursive(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums); // Add the current permutation to the result
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            // Swap the current element with each element after it
            swap(nums[start], nums[i]);
            // Recursively generate permutations for the remaining elements
            permuteRecursive(nums, start + 1, result);
            // Backtrack by restoring the original order
            swap(nums[start], nums[i]);
        }
    }
};