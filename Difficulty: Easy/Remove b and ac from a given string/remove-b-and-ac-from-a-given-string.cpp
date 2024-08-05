//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  public:
    string stringFilter(string str) 
    { 
        //code here.
        for(int i=0 ; i<str.size() ; i++){
            if(str[i]=='b' ){
                str.erase(i,1);
                i--;
                
            }
            else if ( i+1<str.size() and str[i]=='a' and str[i+1]=='c'){
                str.erase(i,2);
                i--;
            }
        }
        
        return str;
    } 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;
   		
   		Solution ob;
   		cout <<ob.stringFilter(s) << "\n";

   		
   	}

    return 0;
}
// } Driver Code Ends