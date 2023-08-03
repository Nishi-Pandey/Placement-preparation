#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        // Create two unordered maps to store the character frequencies in s and t
        std::unordered_map<char, int> freqS, freqT;

        // Count the frequency of characters in string s
        for (char ch : s) {
            freqS[ch]++;
        }

        // Count the frequency of characters in string t
        for (char ch : t) {
            freqT[ch]++;
        }

        // Compare the character frequencies in both strings
        return freqS == freqT;
    }
};