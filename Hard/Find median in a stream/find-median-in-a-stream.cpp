//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
     priority_queue<int> maxpq; 
    priority_queue<int, vector<int>, greater<int>> minpq;
    
    void insertHeap(int &x)
    {
        if (maxpq.empty() || x <= maxpq.top()) {
            maxpq.push(x);
        } else {
            minpq.push(x);
        }
        
        balanceHeaps();
    }
    
    void balanceHeaps()
    {
        while (maxpq.size() > minpq.size() + 1) {
            int top = maxpq.top();
            maxpq.pop();
            minpq.push(top);
        }
        
        while (minpq.size() > maxpq.size()) {
            int top = minpq.top();
            minpq.pop();
            maxpq.push(top);
        }
    }
    
    double getMedian()
    {
        if (maxpq.size() == minpq.size()) {
            return (maxpq.top() + minpq.top()) / 2.0;
        } else {
            return maxpq.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends