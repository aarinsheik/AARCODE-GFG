//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            vector <int> res ;
            
            int n=pat.size();
            int m=txt.size();
            int q=101;
            int d=256;
            int h = 1; 
            
            int pv=0 , tv=0 ;
            
            for(int i=0 ; i<n-1 ; i++){
                h = (h*d)%q;
                if(h<0) h=h+q;
            }
            
            for(int i=0 ; i<n ; i++){
                
                pv = (pv*d + pat[i] )%q;
                tv = (tv*d + txt[i] )%q;
                if(tv<0) tv=tv+q;
                if(pv<0) pv=pv+q;
                
            }
            
            for(int i=0 ; i<=m-n ; i++){
                
                if(pv==tv){
                    
                    int j=0 ;
                    
                    for( j=0 ; j<n ; j++ ){
                        if( pat[j]!=txt[j+i] )
                            break;
                    }
                    
                    if(j==n){
                        res.push_back(i+1);
                    }
                }
                
                if(i<m-n){
                    
                    tv = ( d*( tv - txt[i]*h ) + txt[i+n] )%q ;
                    
                    if(tv<0)
                        tv=tv+q;
                }
            }
            
            if(res.empty()) return {-1};
            else return res;
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends