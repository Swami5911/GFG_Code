//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
         int cnt=0;
            long long int  pro = 1;
            bool check = true;
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] != 0){
                    pro *= nums[i];
                }else{
                    cnt++;
                    check = false;
                }
            }
            long long k=0;
            if(cnt>1){
                for(int i=0;i<nums.size();i++){
                    nums[k]=0;
                    k++;
                }
            }else if (check == false){
                for (int i = 0; i < nums.size(); i++){
                    if (nums[i] != 0){
                        nums[k] = 0;
                        k++;
                    }else{
                       nums[k] = pro;
                        k++;
                    }
                }
            }else{
                for (int i = 0; i < nums.size(); i++){
                    long long int x = pro / nums[i];
                   nums[k] = x;
                    k++;
                }
            }
        return nums;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends