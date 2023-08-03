#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string result = a;
        int count = 1;

        while (result.length() < b.length()) {
            result += a;
            count++;
        }

        if (result.find(b) != string::npos) {
            return count;
        }

        result += a;
        count++;

        if (result.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};
