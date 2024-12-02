//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int> prfar(pat.size(),0);
           int mx=0;
           int i=1 , j=0 ;
           
           while(i<pat.size()){
               
               if(pat[i]==pat[j]){
                   prfar[i]=j+1;
                   j++; i++;
               }
               else{
                   if(j!=0)
                       j=prfar[j-1];
                   else
                       i++;
               }
               
           }
            
            i=0 ; j=0 ;
            vector<int> res;
            
            while( i<txt.size() ){
                
                if( j==pat.size() ){
                    res.push_back(i-j);
                    j=prfar[j-1];
                    continue;
                }
                
                if(txt[i]==pat[j]){
                    i++; j++;
                }
                else if(j==0 or i==0){
                    i++;    
                }
                else{
                    j=prfar[j-1]; 
                }
                
            }
            if( j==pat.size() ){
                res.push_back(i-j);
            }
            
            return res ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends