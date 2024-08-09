//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:

    int MOD=1e9+7;
    
    long long fibo(vector<long long> &dp , int n){
        if(n<=1){
            dp[n]=n;
            return n;
        }
        else if(dp[n]!=-1){
            return dp[n]%MOD;
        }
        
        return dp[n] = ( (fibo(dp , n-1)%MOD) + (fibo(dp, n-2)%MOD) )%MOD ;
        
            
        
    }

    long long int fibSum(long long int n){
        //code here
        vector<long long> dp(n+1,-1);
        
        fibo(dp , n );
        
        long long sum=0 ;
        for(auto i : dp){
            sum=(i+sum)%MOD;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends