//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int maxChars (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << maxChars (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int maxChars (string S)
{
    // your code herestring ns;
    unordered_map<char,int> mp;
    int mx=-1;
    
    for( auto i : S){
        mp[i]=-1;
    }
    
    for(int i=0 ; i<S.size() ; i++){
        if(mp[S[i]]!=-1){
            mx = max(mx, i-mp[S[i]]-1);
        }
        else{
            mp[S[i]]=i;
        }
    }
    
    return mx;
}