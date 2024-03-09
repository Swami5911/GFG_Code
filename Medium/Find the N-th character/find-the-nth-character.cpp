//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string temp="";
        int a=pow(2,r);
        string s_bit="";
        char char_bit=s[n/a];
        if(char_bit=='0')s_bit+="01";
        else s_bit+="10";
        while(r!=0){
            temp="";
            for(char bit:s_bit){
                if(bit=='0')temp+="01";
                else temp+="10";
            }
            s_bit=temp;
            r--;
        }
        return s_bit[n%a];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends