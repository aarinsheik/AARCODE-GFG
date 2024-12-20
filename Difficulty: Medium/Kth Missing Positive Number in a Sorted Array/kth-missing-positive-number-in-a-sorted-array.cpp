//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size() , rk=k ;
        
        k-=abs(arr[0]-1);
        if(k<=0){
            return rk;
        }
        
        for(int i=0 ; i<arr.size()-1 ; i++){
            
            if( k-abs(arr[i+1]-arr[i]-1)<=0 ){
                return arr[i]+k;
            }
            else if( abs(arr[i+1]-arr[i])>1){
                k-=abs(arr[i+1]-arr[i]-1) ;
            }
        }
        
        if( k>0 ){
            return arr[n-1]+k;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends