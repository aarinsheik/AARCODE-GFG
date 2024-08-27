//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    
    int maxSortedAdjacentDiff(vector<int>& arr) {
        // code here
        sort(arr.begin() , arr.end());
        
        int mxdif=0;
        
        for( int i=0 ; i<arr.size()-1 ; i++){
            if(abs(arr[i+1]-arr[i])>mxdif)
                mxdif=abs(arr[i+1]-arr[i]);
        }
        
        return mxdif;
        
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
        Solution ob;
        auto ans = ob.maxSortedAdjacentDiff(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends