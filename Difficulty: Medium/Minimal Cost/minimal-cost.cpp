//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int findCost(int i , vector<int>& arr , int &k , vector<int> &dp ){
        
        if(i>arr.size()){
            return 0;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        
        int mj=1e9 ;
        bool fg = false;
        
        for(int j=1 ; j<=k ; j++){
                if(i+j<arr.size()){
                    fg=true;
                    mj = min( mj , findCost(i+j , arr , k , dp )+abs(arr[i]-arr[i+j]) );
                }
        }
        
        if(!fg)
            mj=0;
            
        return dp[i] = mj;
        
    }
    
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int> dp(arr.size()+1 , -1 );
        return findCost(0,arr,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends