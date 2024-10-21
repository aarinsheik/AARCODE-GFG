//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        int xr = 0 , MOD=10e9+7;
        
        for(int i=0 ; i<arr.size(); i++){
            xr ^= arr[i];
        }
        
        if(xr!=0){
            return 0;
        }
        
        long long co = 2;
        for(int i=2 ; i<=arr.size()-1 ; i++){
            co = (co*2)%MOD;
        }
        
        return co%MOD-1;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends