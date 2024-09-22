//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        vector<int> lps(str.size() , 0 );
        int i=0 , j=1 ;
        
        while(j<str.size()){
            
            if(str[i]==str[j]){
                lps[j]=i+1;
                i++; j++;
            }
            else{
                
                if(i!=0){
                    i=lps[i-1];
                }
                else{
                    j++;
                }
            }
        }
        
        return lps[str.size()-1];
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
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends