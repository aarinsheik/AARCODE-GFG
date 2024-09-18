//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for Java

class Solution {
  public:

    long findIndex(string& str) {
        // Your code goes here
        long i=0 , j=str.size()-1 ; 
        long op=0 , cp=0 ;
        
        for(auto i : str){
            if(i=='(')
                op++;
            else
                cp++;
        }
        
        long cop=0 , ccp=0 ;
        
        for(auto i : str){
            if(i=='(')
                cop++;
            else
                ccp++;
        
            if(cop==cp-ccp)
                return cop+ccp;
            
        }
        
        if(op==0)
            return long(str.size());
        else
            return 0;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.findIndex(str) << endl;
    }
}
// } Driver Code Ends