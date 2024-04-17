//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here  
          int sum=0;
        sort(arr,arr+N);
        int i=N-1;
        while(i-1>=0&&i>=0  )
        {
            if(  arr[i]!=-1 && abs(arr[i]-arr[i-1])<K)
            {
                sum+=arr[i];
                sum+=arr[i-1];
                arr[i-1]=-1;
            }
            i--;
        }
        return sum;


    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends