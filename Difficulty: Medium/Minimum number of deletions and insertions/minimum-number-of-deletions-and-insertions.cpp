//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int findMin( string &s1 , string &s2 , int i , int j , vector<vector<int>> &dp ){
	    
	    
	    if(i<0 and j>=0){
	        return j+1;
	    }
	    if(j<0 and i>=0){
	        return i+1;
	    }
	    
	    if( i<0 or j<0 ){
	        return 0;
	    }
        
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        	    
	    if ( s1[i]==s2[j] ){
	        return dp[i][j] = findMin( s1 , s2 , i-1 , j-1 , dp );
	    }
	    
	    int m1=0 , m2=0 ;
	  
	    m1 = findMin( s1 , s2 , i-1 , j , dp )+1;
	    m2 = findMin( s1 , s2 , i , j-1 , dp )+1;
	    
	    return dp[i][j] = min( m1 , m2 );
	    
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp( str1.size()+1 , vector<int> (str2.size()+1 , 0) ) ;
	    return findMin(str1 , str2 , str1.size() , str2.size() , dp ) ;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends