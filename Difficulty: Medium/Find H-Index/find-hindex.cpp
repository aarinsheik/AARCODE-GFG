//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int n;
    
    bool check(vector<int>&arr, int t){
        int cnt=0;
        for(int i=0; i<n; i++){
            if(arr[i]>=t) cnt++;
        }
        if(cnt>=t) return 1;
        else return 0;
    }
    
    int hIndex(vector<int>& citations) {
        // code here
        int maxi=-1e9, mini=1e9;
        n=citations.size();
        
        for(int i=0; i<n; i++){
            maxi=max(maxi, citations[i]);
            mini=min(mini, citations[i]);
        }
        
        int lo=min(0, mini), hi=max(maxi, n);
        int ans=0;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(citations, mid)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends