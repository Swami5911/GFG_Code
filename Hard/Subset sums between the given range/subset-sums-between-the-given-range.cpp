//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    long long int countSubsets(vector<int>&arr, int n, int l, int r){
        int totalSubsets = 0;
        for (int i = 0; i < (1 << n); ++i) {
            // Generate all possible subsets using bitmasking
            long long int subsetSum = 0;

            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subsetSum += arr[j];
                }
            }

            if (subsetSum >= l && subsetSum <= r) {
                totalSubsets++;
            }
        }

        return totalSubsets;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    int l, r;
	    cin >> l >> r;
	    Solution ob;
	    long long int ans = ob.countSubsets(arr, n, l, r);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends