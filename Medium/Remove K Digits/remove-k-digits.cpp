//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        
        string res ;
        char ch ;
        stack<char> st;
        
        s.push_back('$');
        
        st.push(s[0]);
        
        for(int i=1 ; i<s.size() ; i++){
            
            if(!st.empty() and st.top()<=s[i]){
                st.push(s[i]);
            } 
            else if(st.top()>s[i]){
                while( !st.empty() and k!=0 and st.top()>s[i] ){
                        st.pop();
                        k--;
                    }    
                    st.push(s[i]);
            }
            
        }
        
        st.pop();
        
        while(!st.empty()){
            if(k!=0){
                st.pop();
                k--;
            }
            else{
                res+=st.top();
                st.pop();
            }
        }
        
        for(int i=res.size()-1 ; i>0 ; i-- ){
            if(res[i]=='0'){
                res.pop_back();
            }
            else{
                break;
            }
        }
        
        reverse( res.begin() , res.end() );
        
        if(res.empty()) return "0";
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends