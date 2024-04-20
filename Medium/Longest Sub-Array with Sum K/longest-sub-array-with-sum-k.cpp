//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int, int> mp;
        int p = 0, res = 0;
        
        for(int i = 0; i<n; i++){
            p+=arr[i];
            
            if(p == k){
                res = i+1;
            }
            if(mp.find(p-k)!=mp.end()){
                res = max(res, i-(mp[p-k]));
            }
            mp.insert({p, i});
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends