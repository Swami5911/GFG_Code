//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
         long long int sum=0;
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if( k>0 && a[i]<0)
            { 
                a[i]=-a[i];
                sum+=a[i];
                k--;
            }
            else 
            {
                sum+=a[i];
            }
        }
        if(k%2==0) return sum;
        else
        {
            sort(a,a+n);
            k=k%2;
            sum-=a[0];
            sum+=-a[0];
        return sum;
        }
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