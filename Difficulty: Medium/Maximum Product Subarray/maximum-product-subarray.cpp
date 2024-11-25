//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  
    // Function to find maximum product subarray
    long long maxProduct(vector<int> &arr) {
        // code here
        vector<int> ps ;
        long long mx = -1e9 , pr=1;
        
        for(int i=0 ; i<arr.size() ; i++){
            
            if(arr[i]==0){
                pr=1;
                mx = max( mx , (long long)arr[i] );
            }
            else{
                pr*=arr[i];
                mx = max( mx , pr );
            }
            
        }
        
        pr=1;
        
        for(int i=arr.size()-1 ; i>=0 ; i--){
            
            if(arr[i]==0){
                pr=1;
                mx = max( mx , (long long)arr[i] );
            }
            else{
                pr*=arr[i];
                mx = max( mx , pr );
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
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends