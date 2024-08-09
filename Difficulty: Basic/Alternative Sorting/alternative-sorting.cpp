//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	vector<int> alternateSort(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr , arr+n );
	    
	    int i=0 , j=n-1 , k=0 ;
	    vector<int> res;
	    while(i<=j){
	        
	        if(i==j){
	            res.push_back(arr[i]);
	            break;
	        }
	            
	            
	        if(k++%2==0){
	            res.push_back(arr[j]);
	            j--;
	        }
	        else{
	            res.push_back(arr[i]);
	            i++;
	        }
	    }
	    
	    return res;
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
       	
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
       

        Solution ob;
        vector<int> ans = ob.alternateSort(a, n);
        for(auto i:ans)
        	cout << i << " ";
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends