//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        int len = pre_exp.length();
        stack<string>s;
        for(int i = len - 1; i >= 0; i--)
        {
            string ch = "";
            ch += pre_exp[i];
            if(isalpha(ch[0]))
            {
                s.push(ch);
            }
            else
            {
                string left = s.top();
                s.pop();
                string right = s.top();
                s.pop();
                s.push("(" + left + ch + right + ")");
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends