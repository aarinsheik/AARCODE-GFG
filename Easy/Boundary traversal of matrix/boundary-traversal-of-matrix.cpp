//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > mat, int n, int m) 
    {
        // code here
        vector <int> up , down , ryt , left , res ;
        
        if(n==1 and m==1){
            return {mat[0][0]};
        }
        else if(n==1){
            for(int i=0 ;i<m ; i++){
                res.push_back(mat[0][i]);
            }
            return res;
        }
        else if(m==1){
            for(int i=0 ;i<n ; i++){
                res.push_back(mat[i][0]);
            }
            return res;
        }
        
        for(int i=0 ; i<mat.size() ; i++){
            for(int j=0 ; j<mat[0].size() ; j++ ){
                
                if(i==0){
                    up.push_back(mat[i][j]);
                }
                else if(i==mat.size()-1){
                    down.push_back(mat[i][j]);    
                }
                
                if(j==0 and i!=0 and i!=mat.size()-1){
                    left.push_back(mat[i][j]);
                }
                
                if(j==mat[0].size()-1 and i!=0 and i!=mat.size()-1 ){
                    ryt.push_back(mat[i][j]);
                }
                
            }
        }
        
        reverse(down.begin() , down.end() );
        reverse(left.begin() , left.end() );
        
        res.insert(res.end() , up.begin() , up.end() );
        res.insert(res.end() , ryt.begin() , ryt.end() );
        res.insert(res.end() , down.begin() , down.end() );
        res.insert(res.end() , left.begin() , left.end() );
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends