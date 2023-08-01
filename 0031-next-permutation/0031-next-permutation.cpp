class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Find first index i such that nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Find smallest element in nums[i+1:] that is greater than nums[i]
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }

            // Swap elements at indices i & j
            swap(nums[i], nums[j]);
        }

        // Reverse subarray nums[i+1:]
        reverse(nums.begin() + i + 1, nums.end());
    }
};
