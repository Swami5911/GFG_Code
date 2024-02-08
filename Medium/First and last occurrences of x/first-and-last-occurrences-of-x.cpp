//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> v;
        int res = -1;
        int s = 0, e = n - 1;
        
        while (s <= e) {
            int mid = (s + e) / 2;
            if (arr[mid] == x) {
                res = mid;
                e = mid - 1;
            } else if (x < arr[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        v.push_back(res);
        
        int ans = -1;
        int st = 0, ed = n - 1;
        while (st <= ed) {
            int mid = (st + ed) / 2; 
            if (arr[mid] == x) {
                ans = mid;
                st = mid + 1;
            } else if (x < arr[mid]) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        v.push_back(ans);
        return v;

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends