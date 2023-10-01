//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void swap(int &a , int &b){
        int t = a ;
        a = b ; 
        b = t ;
    }
    
    void rotateby90(vector<vector<int> >& mat, int n) 
    { 
        // code here 
        for(int i=0 ; i<n ; i++){    
            for(int j=0 ; j<floor(n/2) ; j++){
                swap(mat[i][j] , mat[i][n-1-j]);      
            }
        }
        
        for(int i=0 ; i<n ; i++){    
            for(int j=0 ; j<=i ; j++){
                swap(mat[i][j] , mat[j][i]);      
            }
        } 
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
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends