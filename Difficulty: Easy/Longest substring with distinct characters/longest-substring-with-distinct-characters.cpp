//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string S){
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
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends