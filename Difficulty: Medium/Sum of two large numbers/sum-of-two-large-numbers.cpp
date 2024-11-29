//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string s1, string s2) {
        // Your code goes here
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
            
            if(s>9){
                cr=1;
                s=s%10;
            }
            
            res= char('0'+s) + res ;
            i--; j--;
        }
        
        while(i>=0){
            int s=int(s1[i]-'0') + cr ;
            cr=0;
            
            if(s>9){
                cr=1;
                s=s%10;
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

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends