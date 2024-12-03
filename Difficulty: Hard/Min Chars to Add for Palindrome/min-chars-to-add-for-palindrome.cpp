//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string rev = s ;
        reverse( rev.begin() , rev.end() );
        string str= s+rev;
        
        vector<int> lps(str.size(),0);
        
        for(int i=1 , len=0 ; i<str.size() ;){
            
            if(str[i]==str[len]){
                lps[i++]=++len;
            }
            else if( len>0 ){
                len = lps[len-1];
            }
            else{
                lps[i++]=0;
            }
        }
        
        return s.size()-lps[str.size()-1];
        
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
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends