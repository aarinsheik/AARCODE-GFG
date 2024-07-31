//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{   
public:
    int isPossible(string S){
        //Code Here
        vector<string> vs;
        unordered_map<string,int> mp;
        string ts ;
        ts.clear();
        
        int ln = S.size()/4;
        
        if(ln==0){
            return 0;
        }
        
        int i=0 ;
        while(S[i]!='\0'){
            
            ts+=S[i];
            
            if(i%ln==0 or i==S.size()-1){
                vs.push_back(ts);
                mp[ts]++;
                ts.clear();
            }
            i++;
        }
        
        // for(auto j : vs){
        //     cout<<j<<" ";
        // }
        
        if(mp.size()>=4){
            return 1;
        }
        return 0;
        
    }
};
    

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.isPossible(s)<<"\n";
    }
    return 0; 
}
// } Driver Code Ends