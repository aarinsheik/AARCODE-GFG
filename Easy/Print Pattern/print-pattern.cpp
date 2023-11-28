//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void rec( vector<int> &res , int n ){
        
        if(n<=0){
            res.push_back(n);
            return;
        }
        
        res.push_back(n);
        rec(res,n-5);
        res.push_back(n);
        
    }
    
    vector<int> pattern(int N){
        // code here
        vector<int> res ;
        rec( res , N );
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends