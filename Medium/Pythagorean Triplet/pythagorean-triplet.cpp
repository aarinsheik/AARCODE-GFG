//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    int mx=-1;
	    
	    for(int i=0 ; i<n ; i++){
	        mx=max(mx,arr[i]);
	    }
	    
	    vector<int>  h((mx*mx)+1,0);
	    
	    for(int i=0 ; i<n ; i++){
	        h[arr[i]*arr[i]]=1;
	    }
	    
	    for(int i=0 ; i<mx*mx ; i++){
	        
	        if(h[i]==1){
	            
	            for(int j=i ; j<h.size() ; j++){
	                
	                if(j==i and h[j]>1){
	                   
	                   if(i+j<=mx*mx and h[i+j]==1){
	                       return true;
	                   } 
	                }
	                if(h[j]==1 ){
	                    
	                    if( i+j<=mx*mx and h[i+j]==1){
	                        return true;
	                    }    
	                }
	            }
	            
	        }
	        
	    }
	    
	    return false;
	    
	    
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
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends