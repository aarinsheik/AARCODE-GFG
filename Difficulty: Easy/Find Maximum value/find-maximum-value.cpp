//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxValue(vector<int> &arr) {
        // Your code geos here.
        int i=0 , j=arr.size()-1;
        int mx=-1e9;
        
        while(i<j){
            
            mx = max( mx , abs(j-i)*min(arr[i],arr[j]) );
            
            if(arr[i]<arr[j]){
                i++;
            }
            else{
                j--;
            }
        }
        
        return mx;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.maxValue(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends