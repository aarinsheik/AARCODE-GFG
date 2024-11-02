//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isProduct(vector<int> arr, long long x) {
        // code here
        map<long long ,int> mp;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(mp[arr[i]]){
                return true;
            }
            
            if(x%arr[i]==0){
                mp[x/arr[i]]++;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        long long x;
        cin >> x;
        cin.ignore(); // To discard any leftover newline characters

        Solution ob;
        auto ans = ob.isProduct(arr, x);
        cout << (ans ? "true\n" : "false\n");
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends