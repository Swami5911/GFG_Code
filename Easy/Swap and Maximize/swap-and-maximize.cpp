//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int st=0,end=n-1;
    long long sum=0;
    while(st<end){
        sum+=abs(arr[st]-arr[end]); st++;
       if(st<end) sum+=abs(arr[end]-arr[st]); end--;
    }
    sum+=arr[st]-arr[0];
    return sum;
}