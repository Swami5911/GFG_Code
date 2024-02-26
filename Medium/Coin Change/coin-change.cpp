//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int coins[],int N,int sum){
        //base case
         vector<long long int> dp(sum + 1, 0);

    // There is one way to make sum 0, which is by not selecting any coin.
        dp[0] = 1;

    // Fill the DP array
        for (int i = N-1; i >=0; i--) {
            for (int j = coins[i]; j <= sum; ++j) {
                dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum];
}
  
  
    long long int count(int coins[], int n, int sum) {
        
        return solve(coins,n,sum);
        // code here.
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends