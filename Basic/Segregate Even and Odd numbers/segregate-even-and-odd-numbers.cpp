//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    // code here
	    priority_queue <int, vector<int> , greater<int>> se , so ;
	    
	    for(int i=0 ; i<n ; i++ ){
	        
	        if(arr[i]%2==0){
	           se.push(arr[i]);     
	        }
	        else{
	           so.push(arr[i]);     
	            
	        }
	    }
	    int j=0 ;
	    while(!se.empty()){
	        arr[j++]=se.top();
	        se.pop();
	    }
	    while(!so.empty()){
	        arr[j++]=so.top();
	        so.pop();
	    }
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
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends