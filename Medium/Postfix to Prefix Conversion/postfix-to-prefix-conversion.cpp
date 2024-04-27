//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>s;
        string t="";
        for(int i=0;i<post_exp.length();i++){
            char c=post_exp[i];
            if(isalnum(c)){
                string q="";
                q+=c;
                s.push(q);
            }
            else{
                string a=s.top();
                s.pop();
                string b=s.top();
                s.pop();
                t=a+b+c;
                s.push(t);
            }
        }
        string w=s.top();
        reverse(w.begin(),w.end());
        return w;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends