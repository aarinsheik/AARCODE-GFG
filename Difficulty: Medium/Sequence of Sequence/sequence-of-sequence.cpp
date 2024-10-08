//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int Total_Seq( int m , int n ){
        
        if( m<1){
            return 0;
        }
        if(n==1){
            return m;
        }
        
        int res = 0;
        for( int i=m ; i>1 ; i--){
            res += Total_Seq( floor(i/2) , n-1 );
        }
        
        return res;
        
    }
    
    int numberSequence(int m, int n){
        // code here
        int tot = 0;
        tot = Total_Seq( m , n );
        return tot;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends