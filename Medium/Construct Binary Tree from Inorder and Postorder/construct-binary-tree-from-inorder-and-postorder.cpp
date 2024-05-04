//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

     Node* help(int* in,int* post,unordered_map<int,int>& mp,int inStart,int inEnd,int postStart,int postEnd)
    {
        //base case
        if(inStart>inEnd)
        return NULL;
        
        //recursive calls
        //and small calculation
        Node* root=new Node(post[postEnd]);
        
        int ind=mp[post[postEnd]];
        int leftSize=ind-inStart;
        int rightSize=inEnd-ind;
        
        root->left=help(in,post,mp,inStart,ind-1,postStart,postStart+leftSize-1);
        root->right=help(in,post,mp,ind+1,inEnd,postEnd-rightSize,postEnd-1);
        return root;
    }
    Node *buildTree(int in[], int post[], int n) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[in[i]]=i;
        
        return help(in,post,mp,0,n-1,0,n-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends