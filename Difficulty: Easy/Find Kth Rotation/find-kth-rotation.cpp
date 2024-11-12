//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int i=0 , j=arr.size()-1 , k=-1;
        
        if(arr[j]>arr[i]) return 0;
        else if( arr[j-1]>arr[j]) return j;
        
        
        while(i<=j){
            int m=(i+j)/2;
            
            if(m>0 and m<arr.size() and arr[m-1]>arr[m] and arr[m]<arr[m-1] ){
                return m;
            }
            else if( arr[j]>arr[m]){
                j=m;
            }
            else{
                i=m;
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends