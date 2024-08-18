//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int recur(int ti , int ni , vector<int> &a1 , vector<int> &a2  , map<pair<bool,int>,int> &dp ,bool isa1 ){
        
        if(ti==a1.size())
            return 0;
        
        pair<bool,int> pr(isa1,ti); 
        
        if( dp[pr] )
            return dp[pr];
            
        if(a1[ti]>a2[ni]){
            while(ni<a2.size()-1 and a1[ti]>a2[ni])
                ni++;
        }
        
        if(a1[ti]==a2[ni]){
            int p = recur( ti+1 , ni , a1 , a2 , dp , isa1 )+a1[ti];
            int q = recur( ni+1 , ti , a2 , a1 , dp , !isa1 )+a2[ni];
            
            return dp[pr] = max(p,q);
        }
        else{
            return dp[pr] = recur(ti+1 , ni , a1 , a2 , dp , isa1 )+a1[ti];
        }
        
        
    }
    
    int max_path_sum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        map<pair<bool,int>,int> dp;
        
        int p = recur( 0 , 0 , arr1 , arr2 , dp , true);
        int q = recur( 0 , 0 , arr2 , arr1 , dp , false);
        
        return max(p,q);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.max_path_sum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends