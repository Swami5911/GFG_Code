//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	     vector<int> positive, negative;
	      for (int i = 0; i < n; ++i) {
            if (arr[i] >= 0)
                positive.push_back(arr[i]);
            else
                negative.push_back(arr[i]);
        }
        
        int i = 0, j = 0, k = 0;
        bool positiveTurn = true;
        
        while (i < positive.size() && j < negative.size()) {
            if (positiveTurn)
                arr[k++] = positive[i++];
            else
                arr[k++] = negative[j++];
            
            positiveTurn = !positiveTurn;
        }
        
        while (i < positive.size())
            arr[k++] = positive[i++];
        
        while (j < negative.size())
            arr[k++] = negative[j++];
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends