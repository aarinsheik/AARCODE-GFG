//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here
        int co=0 , mx=1 ;
        vector<int> v(s.size()+1) , r(s.size()+1) ;
        string st;
        
        for(int i=s.size() ; i>=0 ; i--){
            
            if((i-1<0 or s[i-1]=='I') and (i<s.size() and s[i]=='D') ){
                v[i]=co;
                co=0;
            }
            
            else if(s[i-1]=='D'){
                co++;
            }
            
        }
        
        r[0] = ( v[0]+1 );
        mx=v[0]+1;
        
        for(int i=1 ; i<v.size(); i++){
            
            if( s[i-1]=='I' ){
                r[i]=v[i]+1+mx;
            }
            else if( s[i-1]=='D' ){
                r[i]=r[i-1]-1;
            }
            mx = max(r[i],mx);
            
        }
        
        for(int j=0 ; j<r.size() ; j++) st.push_back( r[j]+48 ) ;
        
        return st;
        
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
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends