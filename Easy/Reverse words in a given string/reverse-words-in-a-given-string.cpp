//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
       string result;
        int n=S.length();
        int i=0;
        while(i<n){
           while(i<n && S[i]=='.') i++;
               if(i>=n) break;
        int j=i+1;
        while(j<n && S[j]!='.') j++;
        string sub= S.substr(i,j-i);  
        if(result.length() == 0) result=sub;
        else result=sub+"."+result;
        i=j+1;
        }
        return result;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends