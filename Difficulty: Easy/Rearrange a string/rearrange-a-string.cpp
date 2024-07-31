//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        multimap<char,int> mp;
        int num=0  ;
        
        for(int i=0; i<str.size() ; i++){
            
            if(str[i]>='0' and str[i]<='9'){
                num+=int(str[i])-48;
            }
            else if(str[i]>='A' and str[i]<='Z'){
                mp.insert({ str[i] , int(str[i]) });
            }
        }
     
        string ns ;
        ns.clear();
        
        
        for(auto k : mp)
            ns+=k.first;
        
        
        string numstr ; 
        while(num){
            int k=num%10;
            numstr=char(k+48)+numstr;
            num=num/10;
        }
        
        return ns+numstr;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}


// } Driver Code Ends