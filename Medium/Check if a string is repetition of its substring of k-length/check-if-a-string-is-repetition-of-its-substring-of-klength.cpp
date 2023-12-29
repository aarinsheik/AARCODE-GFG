//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n%k!=0 or k>n) return 0;
	    
	    map<string,int> mp;
	    string t="";
	    
	    for(int i=0 ; i<n ; i+=k){
	        t = s.substr(i,k);
	        mp[t]++;
	    }
	    
	    int fg=0;
	    
	    if(mp.size()==1) return 1;
	    else if(mp.size()==2){
	        for(auto i : mp){
	            if(i.second==1){
	                fg=1;
	            }
	        }
	        if(fg) return 1;
	        else return 0;
	    }
        else return 0;	    
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends