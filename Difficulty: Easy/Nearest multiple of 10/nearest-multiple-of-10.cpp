//{ Driver Code Starts
#include <iostream>
using namespace std;
// } Driver Code Ends
#include <algorithm>
class Solution {
    
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
         
        if( n==1 or str[n-1]=='0' )
            return str;
            
        if( str[n-1]<='5' ){
            str[n-1]='0';
            return str;
        }
        
        reverse( str.begin() , str.end() );
        char k = str[1];
        int i=1 ;
        
        str[0] = '0';
        
        while(i<str.size()){
            
            k = char( int(str[i])+1 );
            
            if(k>'9'){
                str[i]='0';
                i++;
            }
            else{
                str[i]=k;
                goto here;
            }
        }
        
        if(str[i-1]=='0'){
            str.push_back('1');
        }
        
        here:
        
        reverse( str.begin() , str.end() );
        return str;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends