//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
         int index=0;
        map<int,vector<int>,greater<int>>mp;
        for(int j=0;j<n;j++)
        {
        int count=0;
            
             for (int i = 31; i >= 0; i--)
            {
                int k = arr[j] >> i;
                    if(k&1)
                    {
                        count++;
                    }
            }
           
            mp[count].push_back(arr[j]);
        }

    for(auto x:mp)
    {
        for(auto y:x.second)
       {
        arr[index++]=y;
        }
    }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends