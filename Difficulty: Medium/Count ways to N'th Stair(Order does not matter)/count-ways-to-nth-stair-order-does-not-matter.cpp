//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	    int MOD=1e9+7;
	    
		int nthStair(int n){
		    //  Code here
		    int basecase[] = {1,1,2,2};
		    if(n<4)
		        return basecase[n];
		  
		    return int(floor(n/2)+1)%MOD;      
		      
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends