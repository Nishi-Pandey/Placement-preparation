class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the candidates array to handle duplicates
        sort(candidates.begin(), candidates.end());
        
        // Generate combinations using backtracking
        generateCombinations(candidates, target, 0, current, result);
        
        return result;
    }
    
private:
    void generateCombinations(const vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current); // Add the current combination to the result
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break; // Stop further exploration if candidate is greater than target
            }
            
            // Skip duplicates to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            current.push_back(candidates[i]);
            generateCombinations(candidates, target - candidates[i], i + 1, current, result); // Generate combinations recursively
            current.pop_back(); // Backtrack
        }
    }
};