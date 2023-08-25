//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int co=S.size();
	    stack <int> s;
	    int j=0;
	    
	    for(int i=0 ; i<co/2 ; i++){
	        s.push(S[i]);
	    }
	    if(co%2!=0){
           for(int j=(co/2)+1 ; j<S.size(); j++){
               if(S[j]!=s.top()){
                   return 0;
               }
               s.pop();
           }    
        }
        else{
            for(int j=(co/2) ; j<S.size(); j++){
               if(S[j]!=s.top()){
                   return 0;
               }
               s.pop();
           }
        }
        
        return 1;
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
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends