//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        
        sort( arr.begin() , arr.end() );
        
        for(int k=arr.size()-1 ; k>=2 ; k--){
            
            int i=0 , j=k-1 ;
            int sum=0 ;
            
            while( i<j ){
                if( arr[i]+arr[j]==arr[k] ){
                    return true;
                }
                else if( arr[i]+arr[j]>arr[k] ){
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        
        return false;
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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends