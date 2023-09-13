//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        
        if(r>n) return 0;
        
        long long mat[n+1][r+1];
        long long p=pow(10,9)+7;
        
        for(int i=0 ; i<=n ; i++){
            for(int j=0 ; (j<i+1 and j<=r) ; j++){
                if(j==0 or i==j){
                    mat[i][j]=1;
                }
                else {
                    mat[i][j]=(mat[i-1][j]%p + mat[i-1][j-1]%p)%p ;
                }
            }
        }
        
        return mat[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends