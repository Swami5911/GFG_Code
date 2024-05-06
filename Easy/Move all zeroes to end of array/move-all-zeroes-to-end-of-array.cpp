//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    vector<int> v1; // Vector to store non-zero elements
    vector<int> v2; // Vector to store zeros

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            v2.push_back(arr[i]);
        } else {
            v1.push_back(arr[i]);
        }
    }

    for (int i = 0; i < v1.size(); i++) {
            arr[i] = v1[i];
        }
        // Fill remaining elements with zeros
        for (int i = v1.size(); i < n; i++) {
            arr[i] = 0;
        }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends