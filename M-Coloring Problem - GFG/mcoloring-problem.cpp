//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours
    // such that no two adjacent vertices of graph are coloured with the same colour.
    bool graphColoringUtil(bool graph[101][101], int m, int n, int v, int color[], vector<int>& colors) {
        if (v == n) {
            colors = vector<int>(color, color + n);
            return true;
        }
        
        for (int c = 1; c <= m; c++) {
            bool isSafe = true;
            for (int i = 0; i < n; i++) {
                if (graph[v][i] && color[i] == c) {
                    isSafe = false;
                    break;
                }
            }
            if (isSafe) {
                color[v] = c;
                if (graphColoringUtil(graph, m, n, v + 1, color, colors)) {
                    return true;
                }
                color[v] = 0; // Backtrack
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        vector<int> colors;
        return graphColoringUtil(graph, m, n, 0, color, colors);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends