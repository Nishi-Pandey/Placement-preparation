class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long result = 0;

        // Step 1: Ignore leading whitespace
        while (i < s.length() && s[i] == ' ')
            i++;

        // Step 2: Check for a sign character
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read in digits
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 5: Clamp the result to the 32-bit signed integer range
            if (result * sign < INT_MIN)
                return INT_MIN;
            if (result * sign > INT_MAX)
                return INT_MAX;
            
            i++;
        }

        // Step 4: Change the sign if necessary
        return result * sign;
    }
};