//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n == 1) return 0;
    
        sort(arr.begin(), arr.end());
        int result = arr[n - 1] - arr[0]; 
    
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
    
        for (int i = 0; i < n - 1; i++) {
            int minVal = min(smallest, arr[i + 1] - k);
            int maxVal = max(largest, arr[i] + k);
            result = min(result, abs(maxVal - minVal));
        }
    
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends