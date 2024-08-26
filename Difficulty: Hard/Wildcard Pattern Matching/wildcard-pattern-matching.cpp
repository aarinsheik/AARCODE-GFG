//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    
    int recur( string &p , string &s , int i , int j , vector<vector<int>> &dp ){
        
        if( i==p.size() and j==s.size() )
            return 1;
            
        if( i==p.size() and j!=s.size() )
            return 0;
        
        if( p[i]=='*' and j==s.size() )
            return recur(p,s,i+1,j,dp);
            
        if( i!=p.size() and j==s.size() )
            return 0;
            
        if( p[i]!='*' and p[i]!='?' and p[i]!=s[j] )
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int a=0 , b=0 , c=0 ;
        
        if(p[i]=='*'){
            a = recur(p,s,i+1,j,dp) ;    
            b = recur(p,s,i,j+1,dp) ;
        }
        c = recur(p,s,i+1,j+1,dp) ;
        
        return dp[i][j] = a|b|c ;
        
    }
    
    int wildCard(string pattern, string str) {
        // code here
        vector<vector<int>> dp( pattern.size() , vector<int> ( str.size() , -1 ) );
        return recur( pattern , str , 0 , 0 , dp );
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends