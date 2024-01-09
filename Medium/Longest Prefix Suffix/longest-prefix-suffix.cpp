//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string pat) {
	    // Your code goes here
	   vector<int> lpsar(pat.size(),0);
	   int mx=0;
	   int i=1 , j=0 ;
	   
	   while(i<pat.size()){
	       
	       if(pat[i]==pat[j]){
	           lpsar[i]=j+1;
	           j++; i++;
	       }
	       else{
	           if(j!=0)
	               j=lpsar[j-1];
	           else
	               i++;
	       }
	       
	   }
	   
	   return lpsar[i-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends