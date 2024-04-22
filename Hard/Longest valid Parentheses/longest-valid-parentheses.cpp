//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
       int ans = 0;
        stack<pair<char,int>> st;
        for(int i=0;i<S.size();i++){
            if(S[i] == ')' and st.size() and st.top().first == '('){
                st.pop();
                ans = max(ans,i-(st.size() ? st.top().second : -1));
            }else{
                st.push({S[i],i});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends