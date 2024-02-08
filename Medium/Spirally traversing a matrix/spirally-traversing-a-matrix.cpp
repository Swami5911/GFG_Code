//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        int lf = 0;
        int rt = c;
        int tp = 0;
        int bt = r;
        vector<int> ans;
        
        while (lf < rt && tp < bt) {
            
            for (int i = lf; i < rt; i++) {
                ans.push_back(matrix[tp][i]);
            }
            tp++;
        
          
            for (int i = tp; i < bt; i++) {
                ans.push_back(matrix[i][rt - 1]);
            }
            rt--;
        
            
            if (tp < bt) {
                for (int i = rt - 1; i >= lf; i--) {
                    ans.push_back(matrix[bt - 1][i]);
                }
                bt--;
            }
        
            if (lf < rt) {
                for (int i = bt - 1; i >= tp; i--) {
                    ans.push_back(matrix[i][lf]);
                }
                lf++;
            }
        }
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends