//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int dp[str1.size()+1][str2.size()+1];
        int ans = -1;
        
        for(int i=0 ; i<=str1.size() ; i++){
            for(int j=0 ; j<=str2.size() ; j++){
                
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
                
                ans = max(ans , dp[i][j]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends