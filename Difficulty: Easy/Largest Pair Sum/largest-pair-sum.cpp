//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int m1=arr[0] , m2 = arr[1] ;
        
        for(int i=2 ; i<arr.size() ; i++ ){
            
            if(arr[i]<m1 and arr[i]<m2){
                continue;
            }
            else if(m1<m2){
                m1=arr[i];
            }
            else{
                m2=arr[i];
            }
        }
        
        return m1+m2;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends