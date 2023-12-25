//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    
    void cofactor(vector<vector<int> > &mat , vector<vector<int> > &temp , int n , int row , int col ){
        
        int i=0 , j=0 ;
        
        for(int r=0 ; r<n ; r++ ){
            for(int c=0 ; c<n ; c++ ){
                
                if( r!=row and c!=col ){
                    temp[i][j]=mat[r][c];
                    j++;
                    if(j==n-1){
                        j=0;
                        i++;
                    }
                }    
            }
        }
        
    }
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > mat, int n)
    {
        // code here 
        int det = 0 ;
        int sign = 1 ; 
        vector< vector<int> > temp( n , vector<int>(n) );
        
        if(n==1) return mat[0][0];
        
        for(int i=0 ; i<n ; i++){
            
            // if(mat[0][i]==0){
            //     sign*=-1;
            //     continue;
            // }
            
            cofactor(mat,temp,n ,0,i);
            det += sign*mat[0][i]*determinantOfMatrix(temp,n-1);
            sign*=-1;
            
        }
        return det;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends