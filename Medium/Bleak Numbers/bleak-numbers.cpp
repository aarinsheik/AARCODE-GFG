//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    
    int csb(int a){
        
        int co=0;
        
        if(a==0) return co;
        if(a==1) return ++co;
        
        while(a!=0 and a!=1 ){
            if(a%2==1) co++;
            a = a/2 ;
        }
        if(a==1) return ++co;
        return co;
    }
    
	int is_bleak(int n)
	{
	    // Code here.
	    int b=n , c=log2(n)+1 ;
	    
	    while( c-- ){
	        if(b+csb(b)==n){
	            return 0;
	        }
	        else{
	            b--;
	        }
	    }
	    
	    return 1;
	    
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends