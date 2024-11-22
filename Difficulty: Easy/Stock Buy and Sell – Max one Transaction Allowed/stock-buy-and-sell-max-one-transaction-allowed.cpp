//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &pr) {
        // code here
        int lw=INT_MAX , mx=0 ;
        
        for(int i=0 ; i<pr.size() ; i++){
            
            if(pr[i]<lw){
                lw=pr[i];
            }
            else{
                mx = max( mx , pr[i]-lw);
            }
            
        }
        
        return mx;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends