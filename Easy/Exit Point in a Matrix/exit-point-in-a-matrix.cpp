//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int di[4]={0,1,0,-1};
    int dj[4]={1,0,-1,0};
    vector<int>ans;
    void solve(int i,int j,int dir,vector<vector<int>>& matrix){
        int n=matrix.size(),m=matrix[0].size();
        if(i>=n or j>=m or j<0 or i<0) {
            ans={i-di[dir],j-dj[dir]};
            return;
        }
        
        if(matrix[i][j]==1){
            matrix[i][j]=0;
            dir=(dir+1)%4;
            solve(i+di[dir],j+dj[dir],dir,matrix);
        }else{
            solve(i+di[dir],j+dj[dir],dir,matrix);
        }
    }
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        solve(0,0,0,matrix);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends