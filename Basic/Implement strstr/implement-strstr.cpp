//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     int j=0 , i=0 ;
     while(j<s.size()){
        while(s[j]==x[i] and i<x.size()){
            i++;j++;
        }
        if(i==x.size()){
            return j-i ;
        }
        else{
            j=j-i;
            i=0;

        }
        j++;
     }
     return -1;
}