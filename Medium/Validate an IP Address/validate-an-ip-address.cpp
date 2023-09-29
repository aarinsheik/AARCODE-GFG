//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            vector <int> st;
            int f=0 , dico=0 ;
            s.append(1,'.');
            int num=0;
            
            for(int i=0 ; i<s.size() ; i++){
                
                if( ( (int)s[i]<48 and (int)s[i]>57 ) and (int)s[i]!=46 )
                    return 0;
                
                if(i<s.size()-1 and s[i]=='.' and s[i+1]=='.')
                    return 0;
                
                if(s[i]!='.'){
                    num=( (int)s[i]-48 )+num*10;
                    dico++;
                }
                else{
                    if( (num<0 or num>255) or dico>3)
                        return 0;
                    
                    if( (int(log10(num) + 1) != dico) ){
                        
                        if(num==0 and dico==1 ){
                            
                        }
                        else{
                            return 0;
                        }
                    }
                    
                    dico=0;
                    num=0;
                    f++;
                    
                }
                
                if(f>4)
                    return 0;
                
            }
            
            if(f!=4){
                return 0;
            }
            
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends