//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=1;i<=n;i++){
            for(int p=1;p<=i;p++){
                cout<<"*";
            }
            
            for(int q=1;q<=((2*n)-(2*i));q++){
                cout<<" ";
            }
            
            for(int r=1;r<=i;r++){
                cout<<"*";
            }
            
                
            
            
            cout<<endl;
        }
        
        for(int i=1;i<=n-1;i++){
            for(int  x=0;x<n-i;x++){
                cout<<"*";
            }
            
               for(int  y=0;y<2*i;y++){
                cout<<" ";
            }
               for(int z=0;z<n-i;z++){
                cout<<"*";
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends