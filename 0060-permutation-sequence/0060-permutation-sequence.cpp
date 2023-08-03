class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        string result;
        k--; // Convert 1-indexed k to 0-indexed
        
        for (int i = 1; i <= n; i++) {
            int index = k / factorial(n - i); // Find the index of the current element
            result += to_string(nums[index]); // Append the current element to the result
            nums.erase(nums.begin() + index); // Remove the current element from the set
            k %= factorial(n - i); // Update k for the next iteration
        }
        
        return result;
    }
    
private:
    int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
};