class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 0;
        int count1 = 0, count2 = 0;
        
        // Step 1: Find the two potential candidates
        for (int num : nums) {
            if (num == num1) {
                count1++;
            } else if (num == num2) {
                count2++;
            } else if (count1 == 0) {
                num1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                num2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Step 2: Count occurrences of the two potential candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == num1) {
                count1++;
            } else if (num == num2) {
                count2++;
            }
        }
        
        // Step 3: Check if the occurrences exceed ⌊ n/3 ⌋
        vector<int> result;
        if (count1 > nums.size() / 3) {
            result.push_back(num1);
        }
        if (count2 > nums.size() / 3) {
            result.push_back(num2);
        }
        
        return result;
    }
};