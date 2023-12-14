//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	
	ll countStrings(int n) {
	    // code here
	    int pv1=1 , pv0=1 , pr1=1 , pr0=1 , mod=1e9+7 ; 
	    
	    for(int i=0 ; i<n-1 ; i++){
	        pr1 = (pv0)%mod ;
	        pr0 = (pv1+pv0)%mod ;
	        pv1 = pr1 ;
	        pv0 = pr0 ;
	    }
	    
	    return (pr1+pr0)%mod ;
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends