//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int mod=1e9+7;
	
	int checkSum( int i , int arr[] , int sum , int &tot , vector<vector<int>> &dp ){
	    
	    if( i!=-1 and dp[i][sum]!=-1 ){
	        return dp[i][sum]%mod;
	    }
	    
	    if(i>=0){
	        int co = 0; 
            
            if( sum+arr[i]==tot )
                co=(co+1)%mod;
            
            if( sum+arr[i] <= tot+1 )
    	        co += checkSum( i-1 , arr , sum+arr[i] , tot , dp )%mod ;
    	    
    	    co += checkSum( i-1 , arr , sum , tot , dp )%mod ;
	        
	        return dp[i][sum]=co%mod;
	        
	    }
	    
	    return 0;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+10,-1));
        return checkSum( n-1 , arr , 0 , sum , dp )%mod;
         
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends