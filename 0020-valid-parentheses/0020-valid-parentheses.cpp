#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closingToOpening = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char ch : s) {
            if (closingToOpening.count(ch)) {
                if (st.empty() || st.top() != closingToOpening[ch]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return st.empty();
    }
};