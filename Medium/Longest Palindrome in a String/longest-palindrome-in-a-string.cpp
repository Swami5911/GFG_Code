//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
         int n=S.size();
        int len=1;
        int starting_index=0;
        //for odd length
        for(int i=1;i<n-1;i++){
            int st=i-1,end=i+1;
            while(st>=0 && end<n){
                if(S[st]==S[end]){
                    if((end-st+1)>len){
                        len=end-st+1;
                        starting_index=st;
                    }
                    st--;
                    end++;
                }
                else break;
            }
        }
        //for even length
        for(int i=0;i<n-1;i++){
            if(S[i]==S[i+1]){
                if(2>len){
                    len=2;
                    starting_index=i;
                }
                int st=i-1;
                int end=i+2;
                while(st>=0 && end<n){
                    if(S[st]==S[end]){
                        if((end-st+1)>len){
                            len=end-st+1;
                            starting_index=st;
                        }
                        st--;
                        end++;
                    }
                    else break;
                }
            }
        }
        return S.substr(starting_index,len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends