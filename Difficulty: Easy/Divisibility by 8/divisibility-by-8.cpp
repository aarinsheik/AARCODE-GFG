//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    int toNum( string st ){
        
        int n=0 ;
        for(int i=0 ; i<st.size() ; i++){
            n=n*10+int(st[i]-'0');
        }
        return n;
    }
    
    int DivisibleByEight(string s){
        //code here
        string st = "";
        
        if(s.size()>=3){
            st.push_back(s[s.size()-3]);
            st.push_back(s[s.size()-2]);
            st.push_back(s[s.size()-1]);
        }
        else
            st=s;
        
        int n = toNum(st);
        
        return (n%8==0)?1:-1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends