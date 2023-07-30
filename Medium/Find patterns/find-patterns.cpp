//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string a, string b){
        // code here
        int co=0 , i=0 , j=0 , f=0;

        while( i<a.length() ){
            
            if(a[i]==b[j]){
                a.erase(i,1);
                j++;
                f=1;
            }
            if(j==b.length()){
                co++;
                j=0;
                i=0;
                continue;
            }
            if(!f){
                i++;
            }
            f=0; 
        }
        
        return co;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends