//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Returns true if str can be coverted to a string
// with k repeated substrings after replacing k
// characters.
bool checkString(string str, int k);

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		string s;
		cin>>s;
		int k;
		cin>>k;
      cout<<checkString(s, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends


/*You are required to complete below method */
bool checkString(string str, int k)
{
    //Your code here
    string ns;
    ns.clear();
    unordered_map<string,int> mp;

    ns+=str[0];
    
    if(str.size()%k!=0){
        return false;
    }

    for(int i=1 ; i<str.size() ; i++ ){
           
        if(i%k==0){
            mp[ns]+=1;
            ns.clear();
        }
        ns+=str[i];
    }
    
    if(mp.size()<=1){
        return true;
    }
    else if( mp.size()==2 ){
        for(auto i : mp){
            if(i.second==1)
                return true;
            else
                return false;
        }
    }
    else{
        return false;
    }
}