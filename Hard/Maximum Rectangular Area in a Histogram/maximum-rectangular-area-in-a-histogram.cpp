//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long>s; 
        s.push(0); 
        
        
        long long res=arr[0];  
        
        
        for(int i=1;i<n;i++){
           
           while(s.empty()==false && arr[s.top()]>=arr[i]){
               long long tp=s.top(); 
                s.pop();
               long long curr=arr[tp]*(s.empty() ? i:i-s.top()-1); 
               
               res=max(res,curr); 
           }   
           
           s.push(i);
        } 
        
         
         while(s.empty()==false){
             long long tp=s.top();  
             s.pop();
             long long curr=arr[tp]*(s.empty() ? n:n-s.top()-1); 
             
             res=max(res,curr);
         }
        
        
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends