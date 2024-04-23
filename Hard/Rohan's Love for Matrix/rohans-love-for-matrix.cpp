//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        long ans = 0;
        long ele1 = 0;
        long ele2 = 1l;
        long mod = 1000000007l;
        for(int i =0 ; i < n ; i++){
            ans = (ele1 + ele2)%mod;
            ele2 = ele1%mod;
            ele1 =ans;
        }
        return (int)(ans%mod);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends