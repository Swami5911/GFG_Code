//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
    public:
    int data;
    int row;
    int col;
    node(int data,int i,int j){
        this->data=data;
        row=i;
        col=j;
    }
};
class compare{
  public:
  bool operator()(node* a,node*b){
      return a->data > b->data;
  }
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          priority_queue<node*,vector<node*>,compare> pq;
          int maxi=INT_MIN;
          int mini=INT_MAX;
          for(int i=0;i<k;i++){
              node* temp=new node(KSortedArray[i][0],i,0);
              mini=min(mini,temp->data);
              maxi=max(maxi,temp->data);
              pq.push(temp);
          }
          int start=mini,end=maxi;
          while(pq.size()>0){
              node* temp=pq.top();
              pq.pop();
              mini=temp->data;
              int row=temp->row;
              int col=temp->col;
              if(maxi-mini < end-start){
                  start=mini;
                  end=maxi;
              }
              if(col+1 <n){
                  node* next=new node(KSortedArray[row][col+1],row,col+1);
              maxi=max(maxi,KSortedArray[row][col+1]);
              pq.push(next);
              }else{
                  break;
              }
          }
          return {start,end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends