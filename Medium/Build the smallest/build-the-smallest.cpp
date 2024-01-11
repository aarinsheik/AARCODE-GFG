//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string s, int k)
{
    //code here.
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