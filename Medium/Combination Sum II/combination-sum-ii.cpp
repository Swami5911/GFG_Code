//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void f(vector<int>&a,int n,int k,set<vector<int>>&ans,vector<int>&temp,int ind){
       
        if(k==0 ){
            ans.insert(temp);
            return ;
        }
         if(ind==n || k<0)
        return;
       
        // if(k>=a[ind]){
         temp.push_back(a[ind]);
        f(a,n,k-a[ind],ans,temp,ind+1);
          temp.pop_back();
        // }
      
        f(a,n,k,ans,temp,ind+1);
       
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        set<vector<int>>ans;
        vector<int>temp;
        sort(arr.begin(),arr.end());
        f(arr,n,k,ans,temp,0);
        // sort(arr.begin(),arr.end());
        vector<vector<int>>fin(ans.begin(),ans.end());
        return fin;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends