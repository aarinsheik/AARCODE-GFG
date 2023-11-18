//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int dist(string s){
        
        unordered_map <char,int> mp;
	    long long co=1 ; 
	    long long mod=1000000000+7;
	    
	    for(int i=0 ; i<s.size() ; i++){
	        
	        if(!mp[s[i]]){
	            
	            mp[s[i]]=co;
	            co=(co+co)%mod;
	        }
	        else{
	            int p=co;
	            co=(co+co)%mod-mp[s[i]];
	            mp[s[i]]=p;
	        }
	        
	    }
	   
	    return co;
    }
    
    string betterString(string str1, string str2) {
        // code here
        if( dist(str1)>=dist(str2) ) return str1;
        else return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends