//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int ar[], int n) {
	    // code here
	    int fl=0 , sl=-1;
		for(int i=0 ; i<n ; i++){
		    if(ar[i]>fl){
		        fl=ar[i];
		    }
		}
		for(int i=0 ; i<n ; i++){
		    if(ar[i]<fl and ar[i]>sl){
		        sl=ar[i];
		    }
		}
		return sl;
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
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends