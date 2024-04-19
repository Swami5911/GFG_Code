//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int mn = INT_MAX;
    vector<vector<int>> memo;
  void solve(int arr[], int n,int sm,int i,int sum){
   
    
     if (i >= n) {
            return;
        }
        if (memo[i][sum] != -1) { // If already computed, return memoized value
            return;
        }
        int x = abs(sum - sm);
        mn = min(mn, abs(x - sum));
        solve(arr, n, sm, i + 1, sum + arr[i]);
        solve(arr, n, sm, i + 1, sum);
        memo[i][sum] = mn; 
        
        
  }
    int minDifference(int arr[], int n)  { 
        // Your code goes here
          int sm = 0;
        for (int i = 0; i < n; i++) {
            sm += arr[i];
        }
        memo.resize(n + 1, vector<int>(sm + 1, -1)); 
        solve(arr, n, sm, 0, 0);
        return mn;
      
      
  }
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends