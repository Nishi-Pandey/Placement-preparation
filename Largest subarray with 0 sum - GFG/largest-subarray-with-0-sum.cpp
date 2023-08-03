//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxLen(vector<int>& A, int n) {
        unordered_map<int, int> prefixSumMap;
        int maxLength = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += A[i];

            if (sum == 0) {
                maxLength = i + 1;
            } else if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[sum]);
            } else {
                prefixSumMap[sum] = i;
            }
        }

        return maxLength;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends