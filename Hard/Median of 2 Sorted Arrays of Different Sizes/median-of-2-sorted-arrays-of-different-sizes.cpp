//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        if(array1.size() > array2.size()) swap(array1,array2);
        int m=array1.size();
        int n = array2.size();
        int low = 0;
        int high = m;
        
        while(low <= high){
            int i1 = (low+high)/2;
            int i2 = (n+m+1)/2-i1;
            int r1=(i1 == m) ? INT_MAX:array1[i1];
            int r2=(i2 == n) ? INT_MAX:array2[i2];
            int l1=(i1 == 0 ) ? INT_MIN:array1[i1-1];
            int l2=(i2 == 0 ) ? INT_MIN:array2[i2-1];
            if(l1<=r2 && l2 <= r1){
                if((n+m)%2 == 0 ){
                    return double(max(l2,l1)+min(r1,r2))/double(2);
                }
                else return max(l2,l1);
            }
            else if(l2 > r1){
                low=i1+1;
            }
            else{
                high = i1-1; 
            }
        }
        return 0.0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends