//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string str) {
        // code here
        int left=0 , right=0 , mx=0 , twice=1 ;
        
        for(auto i : str){
            if(i=='(')
                left++;
            else
                right++;
            
            if(left==right){
                mx = max( mx , 2*left );
            }
            else if( left<right){
                left=right=0;
            }
        }
        
        left=right=0;
        for(auto i=str.rbegin() ; i!=str.rend() ; i++){
            if(*i=='(')
                left++;
            else
                right++;
            
            if(left==right){
                mx = max( mx , 2*left );
            }
            else if( left>right){
                left=right=0;
            }
        }
        
        return mx;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends