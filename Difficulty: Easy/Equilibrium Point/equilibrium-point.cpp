//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int findEquilibrium(vector<int> &arr){
    
        // Your code here
        int sum = 0;
        int temp = 0;
        int n =arr.size();
        
        for (auto i:arr) sum+=i;
        
        for (int i =1; i < n;i++) {
            temp += arr[i-1];
            if (temp == sum-temp-arr[i]) return i;
        }
        
        return -1;
        
    }    

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends