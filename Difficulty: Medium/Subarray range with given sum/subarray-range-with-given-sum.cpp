//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        map<long long,int> mp;
        long long sum=0;
        int co=0;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(mp[sum-tar]){
                co+=mp[sum-tar];
            }
            mp[sum]++;
            sum+=arr[i];
        }
        
        
        if(mp[sum-tar]){
            co+=mp[sum-tar];
        }
        
        return co;
        
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
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends