class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); 
            // Initialize each row with 1

            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
                 // Calculate element using the elements from the previous row
            }

            result.push_back(row);
        }

        return result;
    }
};
