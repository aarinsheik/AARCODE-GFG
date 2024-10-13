//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // Your code here
        if(arr.size()<3){
            return -1;
        }
        
        int f=arr[0] , s=arr[1] , t=arr[2] ;
        
        for(int i=3 ; i<arr.size() ; i++){
            if(f<=s and f<=t and arr[i]>=f){
                f=arr[i];
            }
            else if(s<=f and s<=t and arr[i]>=s){
                s=arr[i];
            }
            else if(t<=s and t<=f and arr[i]>=t){
                t=arr[i];
            }
        }
        
        return min({f,s,t});
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
        cout << ob.thirdLargest(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends