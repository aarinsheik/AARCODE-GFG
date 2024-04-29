//{ Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        // Your code here
        string res="";
        unordered_map<char,int> mp , cc ;

        
        for(int i=0 ; i<s1.size() ; i++){
            mp[s1[i]]++;
        }
        
        for(int i=0 ; i<s2.size() ; i++){
            if( mp[s2[i]] ){
                cc[s2[i]]=1;
            }    
        }
        
        if( mp.size()==cc.size() )
            return "-1";
        
        for(int i=0 ; i<s1.size() ; i++){
            if( cc[s1[i]]!=1 )
                res.push_back(s1[i]);
        }
        
        for(int i=0 ; i<s2.size() ; i++){
            if( cc[s2[i]]!=1 )
                res.push_back(s2[i]);
        }
            
        return res;        
    }

};

//{ Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}

// } Driver Code Ends