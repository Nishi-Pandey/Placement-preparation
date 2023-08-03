#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int start = 0;
        int end = 0;
        unordered_set<char> charSet;

        while (end < n) {
            char c = s[end];
            if (charSet.find(c) == charSet.end()) {
                charSet.insert(c);
                maxLength = max(maxLength, end - start + 1);
                end++;
            } else {
                charSet.erase(s[start]);
                start++;
            }
        }

        return maxLength;
    }
};