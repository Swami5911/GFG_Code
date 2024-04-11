//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int i=0,j=n-1,m1=0,m2=0;
       long long s=0;
    

        while (i<j) {
            if (arr[i] < arr[j]) {
                if(i==0)
                m1=arr[i];
                 m1=max(m1,arr[i+1]);
                 s=s+(m1-arr[i+1]);
                i++;
               
            } else {
                if(j==n-1)
                m2=arr[j];
                m2=max(m2,arr[j-1]);
                s=s+(m2-arr[j-1]);
                j--;
            }
        }

        return s;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends