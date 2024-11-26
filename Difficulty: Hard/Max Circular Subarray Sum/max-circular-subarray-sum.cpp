//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        
        // your code here
        int  sum=0 , totmx=INT_MIN , ovrsm=0;
        
        for(int i=0 ; i<arr.size() ; i++){
        
            sum+=arr[i];
            ovrsm+=arr[i];
            
            if(sum>0){
                totmx = max(totmx, sum);
            }
            else{
                sum=0;
                totmx = max(totmx, arr[i]);
            }
            
        }
        
        sum=0;
        
        for(int i=0 ; i<arr.size() ; i++){
        
            sum+=arr[i];
            
            if(sum<0){
                totmx = max(totmx, ovrsm-sum);
            }
            else{
                sum=0;
                totmx = max(totmx, ovrsm-arr[i]);
            }
            
        }
        
        return totmx;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends