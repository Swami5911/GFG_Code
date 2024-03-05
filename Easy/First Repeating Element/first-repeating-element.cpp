//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int>m;
        int mini=10000001;
        bool milf=false;
        for(int i=0;i<n;i++)
        {
            if(m.find(arr[i])==m.end())
            {
                m[arr[i]]=i;
            }
           else
           {
               mini=min(mini,m[arr[i]]);
               milf=true;
           }
        }
        if(milf)
        return (++mini);
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends