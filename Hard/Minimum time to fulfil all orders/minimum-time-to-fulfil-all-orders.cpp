//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool isvalidtime(vector<int>& A, int mins, int N) {
        int ans=0;
        for(int i=0; i<A.size(); ++i) {
            int sum=0, temp=A[i];
            while(sum<mins) {
                sum+=temp;
                if(sum<=mins) ans++;
                if(ans==N) return true;
                temp+=A[i];
            }
        }
        return false;
    }
    int findMinTime(int N, vector<int>&A, int L){
        //write your code here
        sort(A.begin(),A.end());
        int low=0;
        int high=(N*(2*A[L-1]+(N-1)*A[L-1]))/2;
        
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(isvalidtime(A,mid,N)) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
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
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends