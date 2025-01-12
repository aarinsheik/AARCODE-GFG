//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size() ;
        
        vector<int> p(n,0) , s(n,0) ;
        int v1 = arr[0] , v2=arr[n-1] ;
        
        for(int i=0 ; i<n ; i++){
        
            v1 = max( arr[i] , v1 );
            p[i] = v1;
            
            v2 = max( arr[n-1-i] , v2 );
            s[n-1-i] = v2;
        }
        
        int wat = 0 ;
        
        for(int i=0 ; i<n ; i++){
            
            int mn = min( p[i] , s[i] ) ;
            wat+=abs(mn-arr[i]) ;
            
        }
        
        return wat;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends