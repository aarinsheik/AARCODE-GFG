//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    long long Base9( long long n ){
        if(n<=1)
            return n;
            
        return (n%9) + Base9(n/9)*10 ;
    }
    
    long long findNth(long long n) {
        // code here.
        return Base9( n );
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends