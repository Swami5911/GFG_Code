//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        string str = "";
        bool flag1 = false, flag2 = false;
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(s1[0]=='-')
        {
            flag1 = true;
            n1--;
        }
        if(s2[0]=='-')
        {
            flag2 = true;
            n2--;
        }
        vector<int> v(10000, 0);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for(int i=0;i<n1;i++)
        {
            int carry = 0;
            int j;
            for(j=0;j<n2;j++)
            {
                int num1 = s1[i]-'0';
                int num2 = s2[j]-'0';
                
                int mul = (num1*num2)+carry+v[i+j];
                carry = mul/10;
                int val = mul%10;
                v[i+j] = val;
            }
            if(carry>0)
            {
                v[i+j]+=carry;
            }
        }
        
        reverse(v.begin(), v.end());
        
        int i = 0;
        while(v[i]==0)
        {
            i++;
        }
        
        if(flag1==true && flag2==false|| flag2==true && flag1==false)
        {
            str+='-';
        }
        
        for(i;i<v.size();i++)
        {
            string temp = to_string(v[i]);
            str+=temp;
        }
        
        if(str.length()==1 && str[0]=='-')
        {
            return "0";
        }
        
        if(str.length()==0)
        {
            return "0";
        }
        return str;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends