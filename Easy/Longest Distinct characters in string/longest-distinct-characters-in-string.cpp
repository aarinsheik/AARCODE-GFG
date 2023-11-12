//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    unordered_map<char,int> mp;
    int i=0 , co=0 , mx=0 ;
    
    while(i<S.size()){
        
        if(!mp[S[i]]){
            mp[S[i]]=i+1;
            co++;
            i++;
        }
        else{
            i = mp[S[i]] ;
            mp.clear() ;
            co=0 ;
        }
        
        mx = max(co , mx) ;
        
    }
    
    return mx ;
    
}