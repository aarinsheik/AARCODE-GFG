//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int h=n-1 , l=0 , m=0 , fo=-1;
	    
	    while(h>=l){
	        
	        m=floor((h+l)/2);
	        
	        if(arr[m]==x){
	            fo=m;
	            break;
	        }
	        
	        else if(arr[m]>x){
	            h=m-1;
	        }
	        else{
	            l=m+1;
	        }
	    }
	    
	    l=fo-1 ;
	    h=fo+1 ;
	    
	    if(fo==-1){
	        return 0;
	    }
	    
	    int co=1 , a1=1 , a2=1 ;
	    
	    while(a1 or a2){
	        if(a1 and l>=0 and arr[l]==x){
	           co++; 
	           l--;
	        }
	        else{
	            a1=0;
	        }
	        
	        if(a2 and h<n and arr[h]==x){
	            co++;
	            h++;
	        }
	        else{
	            a2=0;
	        }
	    }
	
	    return co;
	}
	
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends