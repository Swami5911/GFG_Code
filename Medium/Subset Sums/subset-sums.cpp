//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<int>ans;
  public:
   void solve(vector<int>&num,int k,int curr){
    	if(k==num.size()){
    		ans.push_back(curr);
    		return;
    	}
    	solve(num,k+1,curr);
    	solve(num,k+1,curr+num[k]);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        solve(arr,0,0);	
    	sort(ans.begin(),ans.end());
    	return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends