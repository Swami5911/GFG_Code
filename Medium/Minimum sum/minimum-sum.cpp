//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string ans="";
        int c=0;
        for(int i=n-1;i>=0;i-=2){
            int sum=arr[i]+arr[i-1]+c;
            if(sum==0) continue;
            c=sum/10;
            ans=char((sum%10)+'0')+ans;
        }
        if(c) ans=char(c+'0')+ans;
        if(ans=="") return "0";
        return ans;
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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends