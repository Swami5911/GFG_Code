//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> ans;
        sort(candies , candies+N);
        int minCost = 0;
        int maxCost = 0;
        int n = N;
        int k = K;
        for(int i = 0; i < n; i++)
        {
            minCost += candies[i];
            n -= k;
        }
        
        n = N;
        k = K;
        
        sort(candies , candies+N , greater<int>());
        
        for(int i = 0; i < n; i++)
        {
            maxCost += candies[i];
            n -= k;
        }
        
        ans.push_back(minCost);
        ans.push_back(maxCost);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends