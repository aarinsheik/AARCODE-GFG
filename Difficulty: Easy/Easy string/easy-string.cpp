//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends

string numToStr(int i){
    
    string n ;
    while(i){
        int v=i%10;
        n= char(v+int('0')) + n;     // ascii of '0' is 48
        i=i/10;
    }
    
    return n;
}

string transform(string S){
    //complete the function here
    stack<char> st;
    stack<int> stc;
        
    string as;
    as.clear();
    int co=0;
    
    for(auto i : S){
        if(i>='A' and i<='Z'){
            
            char nc = char( int(i)+int('a')-int('A') );
            
            if( !st.empty() and st.top()==nc ){
                int cc = stc.top()+1;
                stc.pop();
                stc.push(cc);
            }
            else{
                st.push(nc);
                stc.push(1);
            }

        }
        else if( i>='a' and i<='z'){
        
            if( !st.empty() and st.top()==i ){
                int cc = stc.top()+1;
                stc.pop();
                stc.push(cc);
            }
            else{
                st.push(i);
                stc.push(1);
            }
        }
    }
    
    S.clear();
    
    while(!st.empty()){
        S = numToStr( stc.top() ) + st.top() + S;
        st.pop();
        stc.pop();
    }
    
    return S;
}

