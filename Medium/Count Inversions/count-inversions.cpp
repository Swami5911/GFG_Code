//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  private:
     long long int merge_helper(long long int arr[], int low, int high, int mid) {
        long long int count = 0;
        int left_size = mid - low + 1;
        int right_size = high - mid;
    
        vector<long long int> left(left_size);
        vector<long long int> right(right_size);
    
        for (int i = 0; i < left_size; i++) {
            left[i] = arr[low + i];
        }
        for (int i = 0; i < right_size; i++) {
            right[i] = arr[mid + 1 + i];
        }
    
        int i = 0;
        int j = 0;
        int k = low;
    
        while (i < left_size && j < right_size) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
                count += (left_size - i);
            }
            k++;
        }
    
        while (i < left_size) {
            arr[k] = left[i];
            i++;
            k++;
        }
    
        while (j < right_size) {
            arr[k] = right[j];
            j++;
            k++;
        }
    
        return count;
    }
  
    long long int merge_sort_helper(long long int arr[], int low, int high) {
        long long int count = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            count += merge_sort_helper(arr, low, mid);
            count += merge_sort_helper(arr, mid + 1, high);
            count += merge_helper(arr, low, high, mid);
        }
        return count;
    }

  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        return merge_sort_helper(arr, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends