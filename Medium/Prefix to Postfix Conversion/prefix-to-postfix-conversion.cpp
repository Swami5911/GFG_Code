//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
         stack<string> s;
        string res="";
        
        for(int i=pre_exp.length()-1; i>=0; i--){
            char c=pre_exp[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='a' && c<='z')){
                s.push(string(1,pre_exp[i]));
            }
            else{
                string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();
                
                res=s1+s2+pre_exp[i];
                s.push(res);
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends