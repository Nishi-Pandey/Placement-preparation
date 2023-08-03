#include <string>
#include <vector>

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> rev1 = parseRevisions(version1);
        vector<int> rev2 = parseRevisions(version2);

        int n = max(rev1.size(), rev2.size());

        for (int i = 0; i < n; i++) {
            int num1 = (i < rev1.size()) ? rev1[i] : 0;
            int num2 = (i < rev2.size()) ? rev2[i] : 0;

            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
        }

        return 0;
    }

private:
    vector<int> parseRevisions(string version) {
        vector<int> revisions;
        int n = version.size();
        int i = 0;

        while (i < n) {
            int num = 0;
            while (i < n && version[i] != '.') {
                num = num * 10 + (version[i] - '0');
                i++;
            }
            revisions.push_back(num);
            i++; // Skip the dot '.'
        }

        return revisions;
    }
};
