//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        
        // Your code here
        bool issp=true , fdneg=false ;
        int i=0 , val=0 ;
        
        while( s[i]!='\0' and s[i]==' '){
            i++;
        }
        
        if( s[i]!='\0' and s[i]=='-'){
            fdneg=true;       
            i++;
        }
        
        while( s[i]!='\0' and s[i]=='0'){
            i++;
        }
        
        int digco=0 ;
        
        while( s[i]!='\0' and s[i]>='0' and s[i]<='9'){
            
            digco++;
                
            if( digco>10){
                if(fdneg){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
            }
        
            val = val*10 + (int(s[i])-int('0')) ;
            i++;
            
        }
        
        if( fdneg ){
            val = -val;
        }
        return val;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends