//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int find_max(int i , int tot , vector<int> &cost , vector<vector<int>> &dp ){
        
        if(cost.size() == i){
            return 0;
        }
        if(dp[i][tot]!=NULL){
            return dp[i][tot] ;
        }
        
        if( cost[i]<=tot ){
            int pr = cost[i] - floor(cost[i]*0.9) ;
            return dp[i][tot] = max( 1 + find_max(i+1 , tot-pr , cost , dp) , find_max(i+1 , tot , cost ,dp) );
        }
        else{
            return dp[i][tot] = find_max(i+1 , tot , cost , dp );
        }
    }
    
    int max_courses(int n, int tot, vector<int> &cost)
    {
        //Code Here'
        vector<vector<int>> dp( n , vector<int> (tot+1) );
        return find_max(0,tot,cost,dp);
        
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends