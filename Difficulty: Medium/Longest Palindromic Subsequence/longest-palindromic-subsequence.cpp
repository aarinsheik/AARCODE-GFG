//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string str) {
        //code here
        string s1 , s2 ;
        
        s1 = str;
        reverse(str.begin() , str.end());
        s2 = str;
        
        int n = str.size();      
        int dp[n+1][n+1] ;
        
        // find the longest common subsequence of 'str' and reversed 'str'
        for(int i=0 ; i<=n ; i++){
            for(int j=0 ; j<=n ; j++){
                
                if(j==0 or i==0 ){
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max( dp[i][j-1] , dp[i-1][j] ); 
                }
                
            }
        }
        
        // subtract len of the str by LCS
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends