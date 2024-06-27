//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int sumOfMinAbsDifferences(int arr[], int n)
    {   
        //code here.
        sort(arr, arr+n);
        int sum = 0;
        sum+= (arr[1]-arr[0]);
        for(int i = 1;i<n-1;i++){
            int a = arr[i] - arr[i-1];
            int b = arr[i+1] - arr[i];
            int m = min(a,b);
            sum +=m;
        }
        sum += arr[n-1]-arr[n-2];
        return sum ;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.sumOfMinAbsDifferences(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends