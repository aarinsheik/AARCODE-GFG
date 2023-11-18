//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    unordered_map <char,int> mp;
	    long long co=1 ; 
	    long long mod=1000000000+7;
	    
	    for(int i=0 ; i<s.size() ; i++){
	        
	        if(!mp[s[i]]){
	            
	            mp[s[i]]=co;
	            co=(co%mod +co%mod )%mod;
	        }
	        else{
	            int p=co;
	            co=((co%mod +co%mod)%mod-mp[s[i]]%mod)%mod;
	            mp[s[i]]=p;
	        }
	        
	    }
	    
	    if(co<0){
	        return co+mod;
	    }
	   
	    return co;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends