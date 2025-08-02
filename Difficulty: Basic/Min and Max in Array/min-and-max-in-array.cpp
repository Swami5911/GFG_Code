// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> a) {
        // code here
        int n=a.size();
        if(n==1){
            return {a[0],a[0]};
        }
        sort(a.begin(),a.end());
        return {a[0], a[n-1] };
    }
};