//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	// Your code here
    	int res=0 , i=0;
    	
    	while( i<str.size() ){
    	    if( int(str[i])>=int('0') and int(str[i])<=int('9') ){
    	        int t=0;
    	        while(i<str.size() and int(str[i])>=int('0') and int(str[i])<=int('9') ){
    	            t=t*10+( int(str[i])-int('0') );
    	            i++;
    	        }
    	        res+=t;
    	        i--;
    	    }
    	    i++;
    	}
    	
    	return res;
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends