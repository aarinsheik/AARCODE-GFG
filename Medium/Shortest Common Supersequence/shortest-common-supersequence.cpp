//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int n, int m)
    {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0 ; i<=n ; i++) dp[i][0]=0;
        for(int j=0 ; j<=m ; j++) dp[0][j]=0;
        
        for(int i=0 ; i<n ; i++ ){
            for(int j=0 ; j<m ; j++ ){
                
                if( s1[i]==s2[j] ){
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else{
                    dp[i+1][j+1]=max( dp[i+1][j] , dp[i][j+1] );
                }
                
            } 
        }
        
        return n+m-dp[n][m] ;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends