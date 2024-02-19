//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int n=s.length();
        int arr[26]={0};
        
        // Hashing
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        
        while(k--){
            sort(arr,arr+26); 
            arr[25]--;   
        }
        
        int ans=0;
        
        for(int i=0;i<26;i++){
            ans+=arr[i]*arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends