//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
  public:
    bool PalinArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i++)
    	{
    	    // Check number is pallindrome
    	    int temp = arr[i], r, sum = 0;
    	    while (temp != 0)
    	    {
    	        r = temp % 10;
    	        sum = sum * 10 + r;
    	        temp /= 10;
    	    }
    	    if (sum != arr[i])
    	        return 0;
    	        // Number is non pallindrome, hence return 0
    	}
    	return 1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
    }

    return 0;
}

// } Driver Code Ends