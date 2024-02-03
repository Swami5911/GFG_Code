//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        vector<int> v;
        sort(arr, arr + n);
        
        for (int i = 0; i < n - 1; i++) {
            int count = 1;  
            while (i < n - 1 && arr[i] == arr[i + 1]) {
                count++;
                i++;
            }
            
            if (count >= 2) {
                v.push_back(arr[i]);
            }
        }
        
        if (v.empty()) {
            v.push_back(-1);
        }
        
        return v;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends