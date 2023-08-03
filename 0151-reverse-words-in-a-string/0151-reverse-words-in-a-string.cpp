#include <sstream>

class Solution {
public:
    string reverseWords(string s) {
        // Remove leading and trailing spaces
        int start = 0, end = s.length() - 1;
        while (start <= end && s[start] == ' ') start++;
        while (start <= end && s[end] == ' ') end--;
        
        // Split the string into words
        stringstream ss(s.substr(start, end - start + 1));
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Reverse the order of the words
        reverse(words.begin(), words.end());
        
        // Concatenate the reversed words with a single space separator
        string result;
        for (const string& w : words) {
            if (!result.empty()) {
                result += ' ';
            }
            result += w;
        }
        
        return result;
    }
};
