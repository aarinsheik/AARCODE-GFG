//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	    int i=0 , co=1;
	    string ts="" , te="";
	    while( co<=(s.size()/2) ){
	        
	        ts = s.substr(i,co) ;
	        te = s.substr(s.size()-co , co );
	       // cout<<ts<<" "<<te<<endl;
	        
	        if( ts == te and s.size()%co==0 ){
	            
	            int fg=0;
	            for(int j=0 ; j<s.size() ; j+=co ){
	                if( s.substr(j,co) != ts ) 
	                    fg=1;
	            }
	            if(fg==0){
	                return 1;
	            }
	        }
	        co++;
	    }
	    
	    return 0;
	    
	    
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
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}
// } Driver Code Ends