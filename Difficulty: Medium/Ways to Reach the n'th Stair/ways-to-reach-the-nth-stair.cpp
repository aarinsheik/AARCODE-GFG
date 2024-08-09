//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    int MOD=1e9+7;
    
    int climb( vector<int> &dp , int n ){
        
        if(n==0){
            return 1;  
        }
        else if(n<=2){
            dp[n]=n;
            return n ;
        }
        else if(dp[n]!=-1){
            return dp[n];
        }
        
        return dp[n] = ( climb(dp,n-1)%MOD +climb(dp,n-2)%MOD )%MOD;
        
    }
    
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        return climb( dp , n );
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends