//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int MOD=1e9+7;
    
    int recur(string &s1 , string &s2 , int i , int j , vector<vector<int>> &dp ){
        
        if(j<0)
            return 1;
            
        if(i<0)
            return 0;
            
        if( dp[i][j]!=-1 )
            return dp[i][j]%MOD ;
         
        int co=0;
    
        if(s1[i]==s2[j])
            co += recur( s1 , s2 , i-1 , j-1 , dp )%MOD ;
        
        co += recur( s1 , s2 , i-1 , j , dp )%MOD;
        
        return dp[i][j] = co%MOD ;
        
    }
    
    int countWays(string s1, string s2) {
        // code here
        vector<vector<int>> dp( s1.size()+1 , vector<int> (s2.size()+1,-1) );
        return recur( s1 , s2 , s1.size()-1 , s2.size()-1 , dp )%MOD;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends