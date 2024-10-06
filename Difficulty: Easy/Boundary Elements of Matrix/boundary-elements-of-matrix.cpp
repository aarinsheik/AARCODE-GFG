//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> BoundaryElements(vector<vector<int>>&mat){
        // Code here
        vector<int> res;
        
        for(int i=0 ; i<mat.size() ; i++){
            for(int j=0 ; j<mat[0].size() ; j++){
                
                if(i==0 or i==mat.size()-1 or j==0 or j==mat.size()-1){
                    res.push_back(mat[i][j]);
                }
                
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		Solution obj;
		vector<int>ans = obj.BoundaryElements(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends