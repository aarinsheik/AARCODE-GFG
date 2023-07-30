//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        // code here
        for(int i=0 ; i<n ; i++){
            for(int s=0 ; s<n-i-1 ; s++){
                cout<<" ";
            }
            for(int a=0 ; a<(i+1) ; a++){
                cout<<"* ";
            }
            cout<<endl;
        }
        for(int i=0 ; i<n ; i++){
            for(int s=n-i; s<n ; s++){
                cout<<" ";
            }
            for(int a=0 ; a<(n-i) ; a++){
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends