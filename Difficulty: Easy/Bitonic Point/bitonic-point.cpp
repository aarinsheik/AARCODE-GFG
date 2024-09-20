//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int i=0 , j=n-1 ;
	    
	    while(i<=j){
	        
	        int m=(i+j)/2 ;
	        
	        if( (m==0 or arr[m]>arr[m-1]) and (m==n-1 or arr[m]>arr[m+1]) ){
	            return arr[m];
	        }
	        
	        if( m<n-1 and arr[m]>arr[m-1] )
	            i=m+1;
	        else if( m>0 and arr[m]>arr[m+1] )
	            j=m-1;
	    }
	    
	    return -1;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends