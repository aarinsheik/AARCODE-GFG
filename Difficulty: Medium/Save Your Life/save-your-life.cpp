//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    string useKandane( vector<int> wt , string w ){
        
        string ss = "", res = "";
        int sum = wt[0], mx = wt[0];  // Initialize mx to the first element in the weight array
        ss.push_back(w[0]);
        res.push_back(w[0]);
        
        for(int i = 1 ; i < wt.size() ; i++) {
            if(sum + wt[i] > wt[i]) {
                ss.push_back(w[i]);
                sum += wt[i];
            }
            else {
                sum = wt[i];
                ss = "";
                ss.push_back(w[i]);
            }
            
            if(mx < sum) {
                mx = sum;
                res = ss;
            }
        }
        
        return res;
    }
    
    string maxSum(string w,char x[], int b[],int n){
      // code here      
        map<char,int> mp;
        vector<int> v;
        
        for(int i=0 ; i<n ; i++){
          mp[x[i]]=b[i];
        }
        
        for(int i=0 ; i<w.size() ; i++){
          if(mp[w[i]]){
            v.push_back(mp[w[i]]);  
          }
          else{
            v.push_back(int(w[i]));
          }
        }
        
        string res = useKandane(v,w);
        
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends