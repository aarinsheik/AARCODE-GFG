//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
        vector <int> res ;
        res.push_back( mat[0][0] );
        
        int i=0 , j=0 , n=mat.size()  , m=mat[0].size() , ld=0 ;
        
        while( true ){
            
            if( ld==0 ){
                if(j<m-1){
                    
                    j=j+1 ;
                    res.push_back( mat[i][j] ) ;
                    ld=(++ld)%2 ;
                    
                    while(j>0 and i<n-1){
                        i=i+1;
                        j=j-1;
                        res.push_back( mat[i][j] ) ;
                    }
                }
                else if(i<n-1){
                    
                    i=i+1 ;
                    res.push_back( mat[i][j] ) ;
                    ld=(++ld)%2 ;
                    
                    while(j>0 and i<n-1){
                        i=i+1;
                        j=j-1;
                        res.push_back( mat[i][j] ) ;
                    }
                }
                else if( i==n-1 and j==m-1 ){
                    break;
                }
            }
            else if(ld==1){
                
                if(i<n-1){
                    
                    i=i+1 ;
                    res.push_back( mat[i][j] ) ;
                    ld=(++ld)%2 ;
                    
                    while(i>0 and j<m-1){
                        i=i-1;
                        j=j+1;
                        res.push_back( mat[i][j] ) ;
                    }
                }
                else if(j<m-1){
                    
                    j=j+1 ;
                    res.push_back( mat[i][j] ) ;
                    ld=(++ld)%2 ;
                    
                    while(i>0 and j<m-1){
                        i=i-1;
                        j=j+1;
                        res.push_back( mat[i][j] ) ;
                    }
                }
                else if( i==n-1 and j==m-1 ){
                    break;
                }
            }
            
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends