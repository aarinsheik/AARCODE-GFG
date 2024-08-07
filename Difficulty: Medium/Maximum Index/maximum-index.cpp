//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        
        vector<int> minar , maxar ;
        int v=1e12;
        
        for(int i=0 ; i<n ; i++){
            if(v>arr[i]){
                v=arr[i];
            }       
            minar.push_back(v);
        }
        
        v=-1;
        
        for(int i=n-1 ; i>=0 ; i--){
            if(v<arr[i]){
                v=arr[i];
            }
            maxar.push_back(v);
        }
        
        reverse(maxar.begin(), maxar.end());
        
        int mdiff=-1 , i=0 , j=0;
        
        while(j<n and i<n ){
            if(minar[i]<=maxar[j]){
                mdiff = max( mdiff , j-i);
                j++;
            }
            else{
                i++;
            }
        }
        
        
        return mdiff;
        
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends