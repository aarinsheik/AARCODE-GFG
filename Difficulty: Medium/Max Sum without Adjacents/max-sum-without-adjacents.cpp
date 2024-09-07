//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int recur( vector<int> &arr , int i , vector<int> &dp ){
	    
	    if(i<0)
	        return 0;
	        
	    if(dp[i]!=0)
	        return dp[i];
	    
	    int s1=0 , s2=0;
	    
	    s1 = recur( arr , i-2 , dp ) + arr[i] ;
	    s2 = recur(arr , i-1 , dp );
	    
	    return dp[i] = max( s1 , s2 );
	    
	}
	
	int findMaxSum(vector<int>&arr, int n) {
	    // code here
	    vector<int> dp(n+1,0) ;
	    return recur( arr , n-1 , dp );
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends