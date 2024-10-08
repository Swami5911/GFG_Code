//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here 
        int i=0,j=0;
        sort(arr.begin(),arr.end());
        
        int ans=0;
        
        while(j<arr.size()){
            
            int diff=arr[j]-arr[i];
            
            if(diff<=k) ans=max(ans,j-i+1);
            if(diff>k) i++;
            else j++;
        }
        return arr.size()-ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends