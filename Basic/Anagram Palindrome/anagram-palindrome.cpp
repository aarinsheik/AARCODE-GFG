//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    
   unordered_map <int,int> mp ; int co=0 , n=S.size();
   
   for(int i=0 ; i<n ; i++){
       if(!mp[S[i]]){
           mp[S[i]]=1;
       }
       else{
           mp[S[i]]=0;
       }
   }
   
   for(int i=0 ; i<26 ; i++){
       if(mp[i+97]){ co++; mp[i+97]=0; }
       if(co>1) return 0;
   }
   
   
   return 1;
}