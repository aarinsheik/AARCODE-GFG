//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    int mxcut( unordered_map<int,int> &dp, int n, int &x, int &y, int &z ){
        
        if(n==0)
            return 0 ;
        if(n<0)
            return -1e9;
        
        if(dp[n])
            return dp[n];
        
        int fmx=-1e9 , fmy=-1e9 , fmz=-1e9 ;
        
        if(n>=x)
            fmx = mxcut(dp , n-x , x , y , z );

        if(n>=y)
            fmy = mxcut(dp , n-y , x , y , z );
        
        if(n>=z)
            fmz = mxcut(dp , n-z , x , y , z );
        
        return dp[n] = max({fmx,fmy,fmz})+1 ;
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        unordered_map<int,int> dp;
        return max( 0, mxcut( dp , n , x , y , z ) );
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends