//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        
        void revStack(stack<char> &str){
            queue<char> q;
            
            while(!str.empty()){
                q.push(str.top());
                str.pop();
            }
            
            while(!q.empty()){
                str.push(q.front());
                q.pop();
            }
        }
        
        bool isIPNum(stack<char> str){
            
            if(str.empty()){
                return false;
            }
            
            int val=0 , num_c = str.size();
            
            revStack(str);
            if(num_c>1 and str.top()=='0')
                    return false;
            
            while( !str.empty() ){
                char c = str.top();
                
                if( c<'0' or c>'9')
                    return false;
                
                val = (val*10)+int(c)-int('0');
                str.pop();
                num_c--;
            }
            
            if(val>=0 and val<=255)
                return true;
                
            return false;
        }
        
        int isValid(string s) {
            // code here
            int i=0 , num_dt=0 , num_ip=0 , sl = s.size();
            stack<char> str ;

            
            while(true){
                
                if(num_dt>=4)
                    return 0;
                
                if( i<sl and s[i]!='.' ){
                    str.push(s[i]);
                }
                else if(sl==i or (i<sl and s[i]=='.') ){
                    
                    if( !isIPNum(str) )
                        return 0;
                    
                    while( !str.empty() ){
                        str.pop();
                    }

                    num_ip++;
                    
                    if(sl==i and num_ip==4 and num_dt==3)
                        return 1;
                    else if(sl==i){
                        return 0;
                    }
                    
                    num_dt++;
                    
                }
                
                i++;    
            }
            
            return 0;
            
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
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends