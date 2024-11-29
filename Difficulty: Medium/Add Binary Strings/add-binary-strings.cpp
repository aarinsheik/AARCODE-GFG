//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        if(s1.size()<s2.size()){
            string t=s1;
            s1=s2;
            s2=t;
        }
        
        string res="";
        
        int cr=0 , i=s1.size()-1 , j=s2.size()-1 ;
        
        while(j>=0){
            int s=int(s1[i]-'0') + int(s2[j]-'0') + cr;
            cr=0;
            
            if(s>1){
                
                if(s%2==0){
                    cr=1;
                    s=0;
                }
                else{
                    cr=1;
                    s=1;
                }

            }
            
            res= char('0'+s) + res ;
            i--; j--;
        }
        
        while(i>=0){
            int s=int(s1[i]-'0') + cr ;
            cr=0;
            
            if(s>1){
                
                if(s%2==0){
                    cr=1;
                    s=0;
                }
                else{
                    cr=1;
                    s=1;
                }

            }
            
            res= char('0'+s) + res ;
            i--;
        }
        
        if(cr>0){
            res= char('0'+cr) + res; 
        }
        
        while(res.size()>1 and res[0]=='0'){
            res = res.substr(1);
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends