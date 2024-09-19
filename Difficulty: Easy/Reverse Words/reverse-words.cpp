//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here
        vector <string> st;
        string str;
        for(int i=0 ; i<S.size() ; i++){
            if(S[i]!='.')
                str.push_back(S[i]);
            else{
                st.push_back(str);
                st.push_back(".");
                str.clear();
            }    
        }
        
        st.push_back(str);
        str.clear();
        reverse(st.begin() , st.end());
        
        for(int i=0 ; i<st.size() ; i++){
            str += st[i];
        }
        
        return str;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends