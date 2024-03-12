//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b, long long mod){
        vector<vector<long long>> res (3, vector<long long>(3,0));
        for(int i =0; i<3; i++){
            for(int j =0; j<3; j++){
                for(int k =0; k<3; k++){
                    res[i][j] = (res[i][j] + a[i][k]*b[k][j])%mod;
                }
            }
        }
        return res;
    }
    
    vector<vector<long long>>  power(vector<vector<long long>> &arr, long long b, long long mod){
        vector<vector<long long >> res = {{1,0,0},{0,1,0},{0,0,1}};
        while(b > 0){
            if(b&1){
                res = multiply(res, arr, mod);
            }
            arr = multiply(arr, arr, mod);
            b /= 2;
        }
        return res;
    }
    long long genFibNum(long long a, long long b, long long c, long long n, long long mod) {
        // code here
        if(mod == 1) return 0;
        if(n <= 2) return 1; 
        n -= 2;
        vector<vector<long long>> mat = {{a,b,1},{1,0,0},{0,0,1}};
        mat = power(mat, n, mod);
        long long res = (mat[0][0] + mat[0][1] + mat[0][2]*c)%mod;
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends