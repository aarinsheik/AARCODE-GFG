//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        
        int val=0;
        //Your code here
        for(int i=0 ; i<str.length() ; i++){
            if(int(str[i]) >= 48 and  int(str[i]) <= 57){
                val = val*10 + (int(str[i])-48) ;
            }
            else if((int(str[i])==45 or int(str[i])==43) and i==0 )
                continue;
            
            else
                return -1;
        }
        
        if(str[0]=='-'){
            return -val;
        }
        return val;
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
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends