//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here   
         string s="";
        while(x!=0){
            s=s+to_string(x%2);
            x=x/2;
        }
        while(s.length()!=32){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
        long long int ans=0;
        for(int i=0;i<32;i++){
            ans=ans+(s[i]-'0')*pow(2,i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends