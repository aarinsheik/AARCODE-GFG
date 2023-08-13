//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    long long fibo(long long k){
        
        long long a=0 , b=1 , c , M=1000000007 ;
        
        if(k==0)return k;
        
        for(long long i=2 ; i<=k  ; i++){
            c = (a+b)%M ;
            a=b;
            b=c;
        }
        
        return c%M;
    }
    
    int nthFibonacci(int n){
      
        return fibo(n);
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