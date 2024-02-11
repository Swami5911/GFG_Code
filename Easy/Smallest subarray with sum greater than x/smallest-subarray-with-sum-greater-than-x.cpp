//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int a = 0, b = 0;
        int ans = INT_MAX;
        int sum = 0;
    
        while (b < n) {
            sum += arr[b];
    
            while (sum > x) {
                ans = min(ans, b - a + 1);
                sum -= arr[a];
                a++;
            }
    
            b++;
        }
    
        return (ans != INT_MAX) ? ans : 0; 
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends