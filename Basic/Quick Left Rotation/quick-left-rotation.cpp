//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   if(k>=n){
	       k=k%n;
	   }
	   
	   int ar[k+1], j=0;
	   
	   for(int i=0 ; i<k ; i++){
	       ar[i]=arr[i];
	   }
	   for(int i=0 ; i<n-k ; i++){
	       arr[i]=arr[i+k];
	   }
	   for(int i=n-k ; i<n ; i++){
	       arr[i]=ar[j++];
	   }
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends