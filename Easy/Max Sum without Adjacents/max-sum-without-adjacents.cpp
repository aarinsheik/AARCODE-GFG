//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here'
	    vector<int> v(n);
	    
	    for(int i=0 ; i<n ; i++){
	        
	        if(i-2>=0 and i-3>=0){
	            v[i]=max( arr[i]+v[i-2] , arr[i]+v[i-3] );
	        }
	        else if(i-2>=0){
	            v[i]=arr[i]+v[i-2];
	        }
	        else{
	            v[i]=arr[i];
	        }
	        
	    }
	    
	    return max(v[n-1],v[n-2]);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
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