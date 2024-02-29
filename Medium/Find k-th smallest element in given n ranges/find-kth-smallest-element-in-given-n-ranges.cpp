//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(),range.end());
        int low=range[0][0];
        int high=range[0][1];
        vector<vector<int>> modified_range;
        for(int i=1;i<n;i++)
        {
            if(range[i][0]<=high)
            {
                high=max(high,range[i][1]);
            }
            else
            {
                modified_range.push_back({low,high});
                low=range[i][0],high=range[i][1];
            }
        }
        modified_range.push_back({low,high});
        vector<int> res;
        for(int i=0;i<q;i++)
        {
            int sz=0,f=0;
            for(auto it:modified_range)
            {
                sz+=it[1]-it[0]+1;
                if(sz>=queries[i])
                {
                    res.push_back(it[1]-sz+queries[i]);
                    f=1;
                    break;
                }
            }
            if(!f) res.push_back(-1);
        }
        return res;

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
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends