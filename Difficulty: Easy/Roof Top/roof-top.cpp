//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int gain=0 , mxGain=-1;
        int i=0 ;
        
        while( i<arr.size()-1 ){
            
            bool con=false;
            
            while( i<arr.size()-1 and arr[i]<arr[i+1]){
                gain++;
                i++;
                con=true;
            }
            
            if(mxGain<gain){
                mxGain=gain;  
            }
            gain=0;
            con ? i : i++ ;
            
        }
        
        return mxGain;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends