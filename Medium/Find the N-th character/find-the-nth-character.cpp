//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string fi=s , se="" ;
        
        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<n+2 ; j++ ){
                if(fi[j]=='1'){
                    se=se+"10";
                }else{
                    se=se+"01";
                }
            }
            fi=se;
            se="";
        }
        
        return fi[n] ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends