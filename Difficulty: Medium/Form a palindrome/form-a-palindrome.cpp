//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
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
        return n-dp[n][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends