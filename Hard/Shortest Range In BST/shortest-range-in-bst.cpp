//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



// } Driver Code Ends
// User function Template for C++

class Solution{
    
    public:
    #define vt vector<int>
    pair<int, int> shortestRange(Node *root) 
    {
        vector<vector<int>>v;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>t;
            while(size--)
            {
                root=q.front();
                q.pop();
                t.push_back(root->data);
                if(root->left)
                   q.push(root->left);
                if(root->right)
                   q.push(root->right);
            }
            v.push_back(t);
        }
        int m=v.size(),mx=0,s,e,diff=INT_MAX;
        priority_queue<vt,vector<vt>,greater<vt>>pq;
        for(int i=0;i<m;i++)
        {
            pq.push({v[i][0],i,0});
            mx=max(mx,v[i][0]);
        }    
        while(!pq.empty())
        {
            int mn=pq.top()[0],i=pq.top()[1],j=pq.top()[2];
            pq.pop();
            if(mx-mn<diff)
            {
                diff=mx-mn;
                s=mn;
                e=mx;
            }
            j++;
            if(j==v[i].size())
               break;
            mx=max(mx,v[i][j]);
            pq.push({v[i][j],i,j});
        }        
        return {s,e};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}
// } Driver Code Ends