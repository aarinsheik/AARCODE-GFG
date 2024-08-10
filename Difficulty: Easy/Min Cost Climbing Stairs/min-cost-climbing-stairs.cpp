//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    
    int MinClimb( unordered_map<int,int> &dp , vector<int> &cost , int n , int ind ){
        
        if(ind>=n){
            dp[ind] = 0;
            return 0;
        }
        
        if(dp[ind]){
            return dp[ind];
        }
        
        int OneStep=0 , TwoStep=0 ;
         
        OneStep = MinClimb( dp , cost , n , ind+1 ) + cost[ind] ;
        TwoStep = MinClimb( dp , cost , n , ind+2 ) + cost[ind] ;
        
        return dp[ind] = min(OneStep , TwoStep);
        
    }
    
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        unordered_map<int,int> dp;
        dp.clear();
        
        int Minstep1 =  MinClimb( dp , cost , N , 0);
        int Minstep2 =  MinClimb( dp , cost , N , 1);
        cost.clear();
        
        return min ( Minstep1 , Minstep2 );
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends