//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int Count(string S);


int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        cout << Count(S) << endl;
    }
return 0;
}


// } Driver Code Ends


int Count(string s){
    //complete the function here
    unordered_map<char,int> mp;
    int co=0;
    
    for(int i=0; i<s.size() ; i++ ){
        
        if(s[i] >= 'A' and s[i]<='Z'){
            mp[char(s[i]+int('a')-int('A'))]++;
        }
        else if(s[i]>='a' and s[i]<='z'){
            mp[s[i]]++;
        }
    }
    
    for(auto i : mp){
        co+=i.second;
    }
    
    return co;
    
}