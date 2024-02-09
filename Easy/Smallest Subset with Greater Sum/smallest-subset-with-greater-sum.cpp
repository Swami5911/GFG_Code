//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(), Arr.end(), greater<int>());
        
        long sumLeft = 0;
        long sumRight = 0;
        int count = 0;
        for(int i=0; i<N; i++)
        {
            sumRight += Arr[i];
        }
        
        for(int i=0; i<N; i++)
        {
            sumLeft += Arr[i];
            sumRight -= Arr[i];
            if(sumLeft <= sumRight)
            {
               count++;
            }
            else
                return count+1;
        }
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends