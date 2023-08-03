class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        generatePartitions(s, 0, current, result);
        return result;
    }
    
private:
    void generatePartitions(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(current); // Add the current partition to the result
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                string substring = s.substr(start, i - start + 1);
                current.push_back(substring);
                generatePartitions(s, i + 1, current, result); // Generate partitions recursively
                current.pop_back(); // Backtrack
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};