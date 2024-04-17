//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
    vector<vector<int>> ans;
    vector<string> st;
    
    for(int i=0; i<row; i++){
        string str = "";
        for(int j=0; j<col; j++){
            str += to_string(M[i][j]);
        }
        
        if(find(st.begin(), st.end(), str) == st.end()){
            st.push_back(str);
        }
    }
   
    for(auto it = st.begin(); it != st.end(); it++){
        vector<int> temp;
        for(int i = 0; i < col; i++){
            temp.push_back((*it)[i]-'0');
        }
        ans.push_back(temp);
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends