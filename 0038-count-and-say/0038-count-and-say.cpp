#include <string>

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1"; // Base case
        }

        string prev = countAndSay(n - 1);
        string result;
        int count = 1;

        // Iterate through the previous term and count the consecutive digits
        for (int i = 0; i < prev.size(); i++) {
            if (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                count++;
            } else {
                result += to_string(count) + prev[i];
                count = 1;
            }
        }

        return result;
    }
};
