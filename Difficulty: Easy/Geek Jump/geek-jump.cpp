//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int MinEn( unordered_map<int,int> &dp , vector<int>& h , int n , int ind ){
        
        if(ind==n-1){
            dp[ind] = 0;
            return 0;
        }
        
        if(dp[ind]){
            return dp[ind];
        }
        
        int OneJ=0 , TwoJ=0 ;
        
        if(ind+1<n) 
            OneJ = MinEn( dp , h , n , ind+1 ) + abs( h[ind]-h[ind+1] ) ;
            
        if(ind+2<n)
            TwoJ = MinEn( dp , h , n , ind+2 ) + abs( h[ind]-h[ind+2] ) ;
        else
            return dp[ind]=OneJ;
        
        return dp[ind] = min(OneJ , TwoJ);
        
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        unordered_map<int,int> dp;
        return MinEn( dp , height , n , 0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends