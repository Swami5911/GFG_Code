//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
     void solve(int i, int j, int n, int m , vector<vector<int>>& grid, vector<int>& ds,
    vector<vector<int>>& ans) {
        
        ds.push_back(grid[i][j]);
        if(i+1<n) solve(i+1,j,n,m,grid,ds,ans);
        if(j+1<m) solve(i,j+1,n,m,grid,ds,ans);
        if(i==n-1 && j==m-1) ans.push_back(ds);
        ds.pop_back();
        
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,0,n,m,grid,ds,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends