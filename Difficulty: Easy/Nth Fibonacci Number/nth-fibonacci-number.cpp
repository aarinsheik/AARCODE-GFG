//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    int MOD=1e9+7;
    
    long long fibo(vector<long long> &dp , int n){
        if(n<=1){
            dp[n]=n;
            return n;
        }
        else if(dp[n]!=-1){
            return dp[n]%MOD;
        }
        
        return dp[n] = ( (fibo(dp , n-1)%MOD) + (fibo(dp, n-2)%MOD) )%MOD ;
        
            
        
    }
    
    int nthFibonacci(int n){
      
        vector<long long> dp(n+1,-1);
        return fibo(dp , n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends