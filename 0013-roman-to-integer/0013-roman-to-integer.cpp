class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToInteger = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            int value = romanToInteger[s[i]];
            if (i + 1 < s.length() && romanToInteger[s[i + 1]] > value) {
                result -= value;
            } else {
                result += value;
            }
        }
        
        return result;
    }
};
