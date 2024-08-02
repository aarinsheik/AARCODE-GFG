//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
        // Code here
        int dp[str1.size()+1][str2.size()+1];
        
        for(int i=0 ; i<str1.size()+1 ; i++){
            for(int j=0 ; j<str2.size()+1 ; j++ ){
                
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else if( str1[i-1]==str2[j-1] ){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if( str1[i-1]!=str2[j-1] ){
                    dp[i][j] = min( min( dp[i-1][j-1] , dp[i][j-1] ) , dp[i-1][j] )+1;
                }
                
            }
        }
        
        return dp[str1.size()][str2.size()];
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends