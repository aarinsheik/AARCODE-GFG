//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    long long fibo(vector<long long> &dp , int n){
        if(n<=1){
            dp[n]=n;
            return n;
        }
        else if(dp[n]!=-1){
            return dp[n];
        }
        
        return dp[n] = ( fibo(dp , n-1)%10 + fibo(dp, n-2)%10 )%10 ;
        
            
        
    }
    
    int fib(int n){
      
        vector<long long> dp(n+1,-1);
        return fibo(dp , n)%10;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.fib(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends