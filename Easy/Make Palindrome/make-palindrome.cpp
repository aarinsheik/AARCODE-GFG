//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        vector <string> v ;
        unordered_map <string,int> mp ;
        int co=0; string p="" ;
        
        for(int i=0 ; i<n ; i++){
            
            p=arr[i];
            reverse(p.begin(), p.end());
            
            
            if(mp[p]){
                mp[p]-=1;
            }
            
            else if(!mp[arr[i]]){
                mp[arr[i]]+=1;
            }
        }
        
        for(int i=0 ; i<n ; i++){
            
            if(mp[arr[i]]){
                co++;
                mp[arr[i]]-=1;
                if(co==1){
                    p=arr[i];
                }
            }
            
            if(co>1) return 0;
        }
        
        if(co==1){
            string q = p;
            reverse(q.begin() , q.end());
            if(q!=p) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends