//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 int j=N-1;
                                                int negInd=-1;
                                                vector<long long> v;
                                                for(int i=N-1;i>=0;i--)
                                                {
                                                    if(A[i]<0)
                                                    {
                                                        negInd=i;
                                                    }
                                                    if(j-i+1==K)
                                                    {
                                                        if(negInd<=j && negInd!=-1)
                                                        {
                                                            v.push_back(A[negInd]);
                                                        }
                                                        else
                                                        {
                                                            v.push_back(0);
                                                        }
                                                        j--;
                                                    }
                                                }
                                                reverse(v.begin(),v.end());
                                                return v;
                                                 
 }