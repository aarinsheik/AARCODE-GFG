//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int s){
        // code here
        string val = "";
        
        if(s<1 and N==1) return "0";
        if(s<1) return "-1";
        
        while(N--){
            if(s>=9){
                val.append("9");
                s-=9;
            }
            else if(s==0){
                val.append("0");
            }
            else{
                string p = to_string(s);    
                val.append(p);
                s-=s;
            }
        }
        
        if(s>0) return "-1";
        
        return val;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends