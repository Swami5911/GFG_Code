//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int a=0;
        int i=0;
        int b=0;
        for(i =0;i<n;i++){
            int s=0;
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    s++;
                
                }}
                if(s>a){
                    a=s;
                    b=i;
                    
             }
             
        
           }
           if(a!=0){return b;
           }
           return -1;
                
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends