//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        unordered_map<char,int> mp ;
        
        int i=0 , j=0;
        int minLen=1e9;
        bool fd=false;
        
        while(i<=j and j<S.size()-1){
            
            while( ( mp['1']==0 or mp['2']==0 or mp['0']==0 ) and j<S.size() ){
                mp[S[j]]++;
                j++;
            }
            
            while( mp[S[i]]>1 and i<j ){
                mp[S[i]]--;
                i++;
            }
            
            if(mp['1']>0 and mp['2']>0 and mp['0']>0 ){
                
                if(j-i==3)
                    return j-i;
                
                minLen = min( minLen , j-i );
                mp.clear();
                i=i+1;
                j=i;
                fd=true;
            }
                
        }
        
        if( !fd )
            return -1;
        
        return minLen;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends