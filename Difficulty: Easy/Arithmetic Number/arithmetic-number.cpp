//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        if(A==B and C==0) return 1;
        
        double dif = B-A;
        double nm1 = dif/C;
        double n = nm1+1;
        
        if( n>0 and n==int(n) ){
            return 1;
        }
        else{
            return 0;
        }
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends