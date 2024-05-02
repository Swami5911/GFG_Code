//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int largestHist(int arr[],int n){
        stack<int> s;
        int res=0;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                int ip=s.top();
                s.pop();
                int curr=arr[ip]*(s.empty()?i:(i-s.top()-1));
                res=max(curr,res);
            }
             s.push(i);
        }
        while(!s.empty()){
            int ip=s.top();
            s.pop();
            int curr=arr[ip]*(s.empty()?n:(n-s.top()-1));
            res=max(res,curr);
        }
        return res;
   }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res=largestHist(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++)
             if(M[i][j]==1)
              M[i][j]+=M[i-1][j];
              
              res=max(res,largestHist(M[i],m));
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends