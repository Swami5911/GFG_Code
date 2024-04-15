//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int>preMin(n),preMax(n),sufMin(n),sufMax(n);
        preMin[0]=arr[0];
        preMax[0]=arr[0];
        for(int i=1;i<n;i++){
            preMin[i]=min(arr[i],preMin[i-1]);
            preMax[i]=max(arr[i],preMax[i-1]);
        }
        sufMin[n-1]=arr[n-1];
        sufMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            sufMin[i]=min(arr[i],sufMin[i+1]);
            sufMax[i]=max(arr[i],sufMax[i+1]);
        }
        
        int ans=INT_MAX;
        for(int i=0;i<=n-k;i++){
            int left_min= i>0 ? preMin[i-1]:INT_MAX;
            int left_max= i>0 ? preMax[i-1]:INT_MIN;
            
            int right_min= i+k<n ? sufMin[i+k]:INT_MAX;
            int right_max= i+k<n ? sufMax[i+k]:INT_MIN;
            
            int mn=min(left_min,right_min);
            int mx=max(left_max,right_max);
            
            ans=min(ans,abs(mn-mx));
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends