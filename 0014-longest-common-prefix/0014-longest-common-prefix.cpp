#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix = "";
        int n = strs[0].length();

        for (int i = 0; i < n; i++) {
            char currentChar = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != currentChar) {
                    return prefix;
                }
            }

            prefix += currentChar;
        }

        return prefix;
    }
};
