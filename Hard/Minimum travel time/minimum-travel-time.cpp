//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& grid) {
        int m = grid[0].size();
        
        int dist[n][m];
        for( int i = 0; i<n; i++ ){
            for( int j = 0; j<m; j++ ) dist[i][j] = INT_MAX;
        }
        
        dist[0][0] = grid[0][0];
        
        queue<pair<int,int>>q;
        q.push({0,0});
        
        int X[4] = { 0, 0, -1, 1 };
        int Y[4] = { -1, 1, 0, 0 };
        
        while( !q.empty() ){
            pair<int,int>p = q.front(); q.pop();
            
            for( int i = 0; i<4; i++ ){
                int x = p.first + X[i];
                int y = p.second + Y[i];
                
                if( x < 0 or y < 0 or x == n or y == m ) continue;
                
                int val = max( grid[x][y], dist[p.first][p.second] );
                
                if( val < dist[x][y] ){
                    dist[x][y] = val;
                    q.push({ x, y });
                }
            }
        }
        
        
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends