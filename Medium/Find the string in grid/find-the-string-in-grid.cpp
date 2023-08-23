//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int find_pat(string w , vector <vector<char>> g , int i , int j){
        
        int d1[8]={-1,-1,-1,0,0,1,1,1};
        int d2[8]={-1,0,1,-1,1,-1,0,1};
        int s1=0 , s2=0 , endc=0;
        
        for(int p=0 ; p<8 ; p++){
            
            endc=0;
            s1=i;
            s2=j;
                
            for(int q = 0 ; q<w.size() ; q++){
                
                if(s1>=0 and s1<g.size() and s2>=0 and s2<g[0].size() ){
                    if(w[q]!=g[s1][s2]){
                        endc=0;
                        break;
                    }
                    else{
                        endc++;
                        if(endc==w.size()){
                            return 1;
                        }
                        s1+=d1[p];
                        s2+=d2[p];
                    }
                }
                else{
                    endc=0;
                    break;
                }
            }
            
        }
        endc=0;
        return 0;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>g, string wd){
	    // Code here
	    vector <vector<int>> v;
	    
	    for(int i=0 ; i<g.size() ; i++){
	        for(int j=0 ; j<g[0].size() ; j++){
	            
	            if(g[i][j]==wd[0]){
	                int m = find_pat(wd,g,i,j);
	                if(m){
	                    v.push_back({i,j});
	                }
	            }
	        }
	    }
	    return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends