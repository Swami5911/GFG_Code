//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getpivot(int A[], int l, int h) {
        int s = l;
        int e = h;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (A[mid] > A[e])
                s = mid + 1;
            else
                e = mid;
        }
        return s;
    }

    int binarysearch(int A[], int l, int h, int key) {
        int s = l;
        int e = h;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (A[mid] == key)
                return mid;
            else if (A[mid] < key)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }

    int search(int A[], int l, int h, int key) {
        int pivot = getpivot(A, l, h);

        if (pivot == 0)
            return binarysearch(A, l, h, key);
        if (key >= A[0])
            return binarysearch(A, l, pivot - 1, key);
        return binarysearch(A, pivot, h, key);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}
// } Driver Code Ends