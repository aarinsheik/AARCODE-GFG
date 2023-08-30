//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    
	    vector <string> v ;
	    unordered_map <string,int> mp;
	    
	    void swap( string &s , int i ,int j ){
	        char t = s[i];
	        s[i]=s[j];
	        s[j]=t;
	    }
	    
	    void permu( string s , int i , int j ){
	        
	        for(int j=i ; j<s.size() ; j++){
	            swap(s,i,j);
	            permu(s,i+1,j);
	        }
	        if(!mp[s]){
	            v.push_back(s);
	            mp[s]=1;
	        }
	    }
	    
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    if(v.size()>0) v.clear();
		    if(mp.size()>0) mp.clear();
		    permu(S,0,0);
		    
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends