//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
	class dsu{
    public:
    vector<int> sz,parent;
    int size;
    dsu(int size){
        this->size = size;
        sz.resize(size),parent.resize(size);
        for(int i=0;i<size;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int a,int b){
        a = find(a),b = find(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            sz[a] += sz[b];
            parent[b] = a;
        }
    }
};
class Solution{
    public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
    {
        // code here
        dsu ds(n+1);
        vector<vector<int>> v;
        vector<int> wts;
        for(auto &ele:edges){
            v.push_back({ele[2],ele[0],ele[1]});
            wts.push_back(ele[2]);
        }
        sort(v.begin(),v.end());
        sort(wts.begin(),wts.end());
        vector<int> val;
        for(auto &ele:v){
            int wt = ele[0],a = ele[1],b = ele[2];
            a = ds.find(a);
            b = ds.find(b);
            if(a!=b){
                val.push_back(ds.sz[a]*ds.sz[b]);
                ds.Union(a,b);
            }
        }
       // for(auto &ele:val) cout<<ele<<" ";
       // cout<<endl;
        for(int i=1;i<val.size();i++){
            val[i] += val[i-1];
        }
        vector<int> ans;
        for(auto &q:queries){
            int idx = upper_bound(wts.begin(),wts.end(),q) - wts.begin();
            if(idx==0) ans.push_back(0);
            else 
            ans.push_back(val[idx-1]);
        }
        return ans;
	}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends