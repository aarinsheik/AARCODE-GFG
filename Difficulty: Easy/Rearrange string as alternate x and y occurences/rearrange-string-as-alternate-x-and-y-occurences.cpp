//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str, int x, int y)
    {
        //code here.
        int zc=0 , oc=0;
        
        for(int i=0 ; i<str.size() ; i++){
            if(str[i]=='0')
                zc++;
            else
                oc++;
        }
        
        str.clear();
        
        while(zc or oc){
            
            int xt=x , yt=y;
            
            while(zc and xt){
                str.push_back('0');
                xt--;
                zc--;
            }
            
            while(oc and yt){
                str.push_back('1');
                yt--;
                oc--;
            }
            
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s, x, y) << endl;
    }
return 0;
}


// } Driver Code Ends