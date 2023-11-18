//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
struct trie{
    struct trie *ch[26] ;
};

int countDistinctSubstring(string s)
{
    //Your code here
    trie* root = new trie();
	    trie* nd = new trie();
	    
	    int n = s.size() , co=0 ;
	    
	    for(int i=0 ; i<n ; i++){
	        
	        nd=root;
	        
	        for(int j=i ; j<n ; j++){
	            
	            if(nd->ch[s[j]-'a']==NULL){
	                co++;
	                trie* t = new trie();
	                nd->ch[s[j]-'a']=t;
	            }
	            nd = nd->ch[s[j]-'a'];
	        }
	    }
	    
	    return co+1;
}