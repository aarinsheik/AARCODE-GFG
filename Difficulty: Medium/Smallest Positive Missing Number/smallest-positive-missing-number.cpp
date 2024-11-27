//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    
    void swap(int &a , int &b){
        int k=a;
        a=b;
        b=k;
    }
    
    
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        
        for(int i=0 ; i<n ; i++){
            while(arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]){
                swap(arr[arr[i] - 1], arr[i]);
            }
        }
        
        for(int i=0 ; i<n ; i++){
            if(arr[i]-1!=i){
                return i+1;
            }
        }
        
        return *max_element(arr.begin() , arr.end() )+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends