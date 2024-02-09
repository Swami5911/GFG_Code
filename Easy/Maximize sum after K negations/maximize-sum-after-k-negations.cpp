//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        long long int sum=0;
            for(int i=0;i<n&&k>0&&a[i]<0;i++){
                a[i]*=-1;
                k--;
            }
        if(k%2!=0){
            int m=INT_MAX,idx=0;
            for(int i=0;i<n;i++){
                if(a[i]<m){
                    m=a[i];
                    idx=i;
                }
            }
            a[idx]*=-1;
        }
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends