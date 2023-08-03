class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the array to use two-pointer technique.
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the fixed element.
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int target = -nums[i];
                int left = i + 1, right = n - 1;
                
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    
                    if (sum == target) {
                        // Found a triplet, add it to the result.
                        result.push_back({nums[i], nums[left], nums[right]});
                        
                        // Skip duplicates for the left and right pointers.
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};
