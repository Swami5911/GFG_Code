//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
  
    long long int floorSqrt(long long int x) 
    {
        int s = 0;
        int e = x;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == x)
                return mid;
            
            if(square < x ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

    // double morePrecision(int n, int precision, int tempSol) {
        
    //     double factor = 1;
    //     double ans = tempSol;
    
    //     for(int i=0; i<precision; i++) {
    //         factor = factor/10;
    
    //         for(double j=ans; j*j<n; j= j+factor ){
    //             ans = j;
    //         }
    //     }
    //     return ans;
    // }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends